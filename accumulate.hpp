//
// Created by rotem levy on 11/06/2020.
//

#include <iostream>
using namespace std;
namespace itertools
{
    template<typename T> class accumulate
    {

    private:

        class iter{
        private:
            int at;
            //  R prev;
        public:
            iter(int at) : at(at) /*,prev(0)*/{}
            bool operator!=(iter const& other) const { return at != other.at; }
            int const& operator*() const { return at/*+prev*/; }
            iter& operator++() { /*prev += at;*/ ++at; return *this; }
        };

        const T& m_container;
    public:
        accumulate(const T& container): m_container(container)
        {
        }
        template<typename K>
        accumulate(K func,const T& container): m_container(container) {};

        iter begin() {
            return iter(0);
        }

        iter end() {
            return iter(2);
        }
    };
};