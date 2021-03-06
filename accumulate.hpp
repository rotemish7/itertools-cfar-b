//
// Created by rotem levy on 11/06/2020.
//
#pragma once

namespace itertools
{
    typedef struct
    {
        template <typename P>
        P operator ()(P x, P y) const { return x+y; }
    }plus;

    template  <typename T,typename F=plus>
    class accumulate
    {
        T cont;
        F func;
        typedef typename T::value_type value_type;
    public:
        accumulate (T c,F f=plus()) : cont(c), func(f) {}

        class iterator
        {
            typename T::iterator first_val;
            typename T::iterator last_val;
            typename T:: value_type result;
            F func;

        public:
            iterator(typename T::iterator start, typename T::iterator end, F f) : first_val(start), last_val(end), func(f), result(*first_val){}
            auto operator*() const {return result;}
            iterator &operator++()
            {
                ++first_val;
                if(first_val!=last_val)
                {
                    result = func(result,*first_val);
                }
                return *this;
            }
            iterator operator++(int)
            {
                iterator copy=*this;
                ++first_val;
                if(first_val!=last_val)
                {
                    result = func(result,*first_val);
                }
                return copy;
            }
            bool operator==(const iterator &other) const { return this->first_val == other.first_val; }
            bool operator!=(const iterator &other) const { return this->first_val != other.first_val; }
        };//class iterator
        iterator begin() {return iterator  (cont.begin(),cont.end(),func);}
        iterator end() { return iterator (cont.end(),cont.end(),func);}
    }; //class accumulate
}//namespace itertools