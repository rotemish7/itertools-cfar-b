//
// Created by rotem levy on 11/06/2020.
//
#pragma once

namespace itertools
{
    template  <typename T,typename F>
    class filterfalse
    {
        T cont;
        F func;
    public:
        filterfalse (F f,T c)  : cont(c), func(f) {}
        class iterator
        {
            typename T::iterator first_val;
            typename T::iterator last_val;
            F func;

        public:
            iterator(typename T::iterator start, typename T::iterator end, F f) : first_val(start), last_val(end), func(f){}
            auto operator*()
            {
                while(func(*first_val))
                    ++(*this);
                return *first_val;
            }
            const iterator &operator++()
            {
                ++first_val;
                while(first_val!=last_val&&func(*first_val))
                    ++first_val;
                return *this;
            }
            iterator operator++(int)
            {
                iterator copy=*this;
                ++first_val;
                while(first_val!=last_val&&func(*first_val))
                    ++first_val;
                return copy;
            }
            iterator& operator=(const iterator& other)
            {
                if (*this != other)
                {
                    this->last_val=other.last_val;
                    this->first_val=other.first_val;
                    this->func=other.func;
                }
                return *this;
            }
            bool operator==(const iterator &other) const
            {
                return this->first_val == other.first_val;
            }
            bool operator!=(const iterator &other) const
            {
                return this->first_val != other.first_val;
            }
        };//class iterator
        iterator begin() {return iterator  (cont.begin(),cont.end(),func);}
        iterator end() { return iterator (cont.end(),cont.end(),func); }

    }; //class filterfalse
}//namespace itertools 
