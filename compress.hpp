//
// Created by rotem levy on 11/06/2020.
//

#include <iostream>
using namespace std;

namespace itertools
{
    template<typename T,typename F>
    class compress
    {
            private:
                const T& container1;
                const F& container2;
            public:

                compress (T con1,R con2)  : container1(con1), container2(con2) {}
                class iterator
                {
                    typename T::iterator first_val1;
                    typename T::iterator last_val1;
                    typename F::iterator first_val2;
                    typename F::iterator last_val2;

                    public:
                        iterator(typename T::iterator first1, typename T::iterator last1,typename F::iterator first2, typename F::iterator last2) : first_val1(first1), last_val1(last1),first_val2(first2), last_val2(last2) {}
                         auto operator*()
                        {
                            while(first_val1!=last_val1&& !*first_val2)
                            {
                                ++(*this);
                            }
                            return *first_val1;
                        }
                        //++first_val
                        iterator &operator++()
                        {
                            ++first_val1;
                            ++first_val2;
                            while(first_val1!=last_val1&&!*first_val2)
                            {
                                ++first_val1;
                                ++first_val2;
                            }
                            return *this;
                        }
                        //first_val++
                        iterator operator++(int)
                        {
                             iterator copy=*this;
                             ++first_val1;
                             ++first_val2;
                             while(first_val1!=last_val1 && !*first_val2)
                            {
                                ++first_val1;
                                ++first_val2;
                            }
                             return copy;
                        }
                         bool operator==(const iterator &other) const { return first_val1 == other.first_val1;}
                         bool operator!=(const iterator &other) const { return first_val1 != other.first_val1;}
                };
                iterator begin() {return iterator(container1.begin(),container1.end(),container2.begin(),container2.end());}
                iterator end() { return iterator(container1.end(),container1.end(),container2.end(),container2.end()); }
    };
}
