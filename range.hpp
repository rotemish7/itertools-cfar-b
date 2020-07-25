//
// Created by rotem levy on 11/06/2020.
//
#pragma once

namespace itertools
{
    class range
    {
        public:
            class iterator
            {
                friend class range;
                private:
                    int at;
                public:
                    iterator(int i) : at(i) {}
                    int operator*() const { return at;}
                    bool operator!=(const iterator& other) const { return at != other.at; }
                    bool operator==(const iterator& other) const {return at == other.at;}
                    iterator operator++(int)
                    {
                        iterator copy = *this;
                        ++at;
                        return copy;
                    }
                    const iterator& operator++() { ++at; return *this; }
                };

                typedef int value_type;
                range(int first, int last) : first_val(first), last_val(last) {}
                iterator begin() const { return first_val; }
                iterator end() const { return last_val; }
        private:
            iterator first_val;
            iterator last_val;
    };
}
