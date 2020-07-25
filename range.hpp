//
// Created by rotem levy on 11/06/2020.
//

namespace itertools
{
    template<typename T> class range
    {
    private:

        class iter{
        private:
            T at;
        public:
            iter(T at) : at(at) {}
            bool operator!=(iter const& other) const { return at != other.at; }
            T const& operator*() const { return at; }
            iter& operator++() { ++at; return *this; }
        };

        T first_val;
        T last_val;

    public:

        range(T first_val, T last_val) :
                first_val(first_val), last_val(last_val) { }
        const iter begin() const{ return iter(first_val); }
        const iter end()  const { return iter(last_val); }
        iter begin() { return iter(first_val); }
        iter end() { return iter(last_val); }
    };
};