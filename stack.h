#ifndef CONTAINERS_STACK_H
#define CONTAINERS_STACK_H

#include <vector>

namespace containers {

    template<typename T>
    class stack : protected std::vector<T> {
        /*protected inherritance because we don't want someone to modify the underlying list*/

    public:

        stack(std::size_t size) : std::vector<T>(size) { };

        T pop() {
            /*get (and remove) the element on the top of the stack*/
            T out = this->back();
            this->pop_back();
            return out;
        }

        void push(const T &val) { std::vector<T>::push_back(val); }

        void push(T &&val) { std::vector<T>::push_back(val); }

        bool empty() { return std::vector<T>::empty(); }
        
        std::size_t size() { return std::vector<T>::size(); }

    };

}
#endif //CONTAINERS_STACK_H
