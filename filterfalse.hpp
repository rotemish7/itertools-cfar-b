//
// Created by rotem levy on 11/06/2020.
//
#pragma once
#include <iostream>
using namespace std;

namespace itertools
{
    template<typename T, typename F>
    class filterfalse
    {
        private:
            T cont;
            F func;
        public:
            filterfalse(T c, F f) : cont(c), func(f) {}

            class iterator
            {
                private:
                    typename T::iterator first_val;
                    typename T::iterator last_val;
                    F func;
                public:
                    iterator(typename T::iterator first, typename T::iterator last, F f) : first_val(first), last_val(last),
                                                                                   func(f) {}

                    bool operator==(const iterator &other) { return first_val == other.first_val; }

                    bool operator!=(const iterator &other) const { return first_val != other.first_val; }

                    auto operator*()
                    {
                        while (func(*first_val))
                        {
                            ++(*this);
                        }
                        return first_val;
                    }

                    //++first_val
                    iterator operator++()
                    {
                        ++first_val;
                        while (first_val != last_val && func(*first_val))
                        {
                            ++first_val;
                        }
                        return *this;
                    }

                    //first_val++
                    const iterator operator++(int)
                    {
                        iterator copy = *this;
                        ++first_val;
                        while (first_val != last_val && func(*first_val))
                        {
                            ++first_val;
                        }
                        return copy;
                    }
                };

                iterator begin() { return iterator (cont.begin,cont.begin,func);}
                iterator end() { return iterator (cont.end,cont.end,func);}
    };
}
