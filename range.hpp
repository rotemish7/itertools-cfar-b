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
        public:
            int operator*() const {return at;}
            const iterator &operator++() {++at;return *this;}
            iterator operator++(int)
            {
                iterator copy(*this);
                ++at;
                return copy;
            }
            bool operator==(const iterator &other) const { return this->at == other.at; }

            bool operator!=(const iterator &other) const { return this->at != other.at; }
        protected:
            iterator(int i) : at(i) {}
        private:
            int at;
        };//class iterator
        iterator begin() const {return first_val;}
        iterator end() const {return last_val;}
        range(int begin, int end) : first_val(begin), last_val(end) {}
        typedef int	value_type;
    private:
        iterator first_val;
        iterator last_val;
    }; //class range
}//namespace itertools