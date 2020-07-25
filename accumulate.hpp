//
// Created by rotem levy on 11/06/2020.
//
#pragma once
#include <iostream>
using namespace std;

namespace itertools
{

    typedef struct
    {
        template <typename P>
        P operator()(P x, P y) const
        {
            return x+y;
        }
    }plus;

    template<typename T, typename F=plus>
    class accumulate
    {
        private:
            const T& cont;
            const F& func;
        public:
            accumulate(T c, F f=plus()): cont(c), func(f) {};

            class iterator
            {
                private:
                   typename T::iterator first_val;
                   typename T::iterator last_val;
                   typename T::value_type result;
                    F func;

                public:
                    iterator(typename T::iterator first, typename T::iterator last, F f) : first_val(first), last_val(last), func(f), result(*first_val){}
                    auto operator*() const {return result;}
                    iterator& operator++()
                    {
                        ++first_val;
                        if(first_val!=last_val)
                            result = func(result,*first_val);
                        return *this;
                    }
                    iterator operator++(int)
                    {
                        iterator copy=*this;
                        ++first_val;
                        if(first_val!=last_val)
                            result = func(result,*first_val);
                        return copy;
                    }
                    bool operator==(const iterator &other) const { retrun first_val == other.first_val; }
                    bool operator!=(const iterator &other) const { retrun first_val != other.first_val; }
            };//class iterator

            iterator begin() {return iterator  (cont.begin(),cont.end(),func);}
            iterator end() { return iterator (cont.end(),cont.end(),func); }
    };
};