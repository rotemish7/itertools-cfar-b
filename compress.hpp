//
// Created by rotem levy on 11/06/2020.
//
#pragma once

namespace itertools
{
    template  <typename T,typename F>
    class compress
    {
        T container1;
        F container2;
    public:
        compress (T con1,F con2)  : container1(con1), container2(con2) {}
        class iterator
        {
            typename T::iterator first_val;
            typename T::iterator last_val;
            typename F::iterator first_flag;
            typename F::iterator last_flag;

        public:
            iterator(typename T::iterator start1, typename T::iterator end1,typename F::iterator start2, typename F::iterator end2) : first_val(start1), last_val(end1),first_flag(start2), last_flag(end2) {}
            auto operator*()
            {
                while(first_val!=last_val&&!*first_flag)
                {
                    ++(*this);
                }
                return *first_val;
            }
            iterator &operator++()
            {
                ++first_val;
                ++first_flag;
                while(first_val!=last_val&&!*first_flag)
                {
                    ++first_val;
                    ++first_flag;
                }
                return *this;
            }
            iterator operator++(int)
            {
                iterator copy=*this;
                ++first_val;
                ++first_flag;
                while(first_val!=last_val&&!*first_flag)
                {
                    ++first_val;
                    ++first_flag;
                }
                return copy;
            }
//            iterator& operator=(const iterator& other)
//            {
//                if (*this != other)
//                {
//                    this->last_val=other.last_val;
//                    this->first_val=other.first_val;
//                    this->func=other.func;
//                }
//                return *this;
//            }
            bool operator==(const iterator &other) const { return this->first_val == other.first_val; }
            bool operator!=(const iterator &other) const { return this->first_val != other.first_val; }
        };//class iterator
        iterator begin() {return iterator  (container1.begin(),container1.end(),container2.begin(),container2.end());}
        iterator end() { return iterator (container1.end(),container1.end(),container2.end(),container2.end()); }
    }; //class compress
}//namespace itertools