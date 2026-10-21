#ifndef VECTOR_H
#define VECTOR_H

// A vector in C++ is a dynamic sequence container provided by the Standard Template Library (STL). It stores elements in contiguous memory and automatically manages its storage as elements are added or removed.
// Vectors can dynamically grow or shrink during program execution.
// They provide constant-time random access and support efficient insertion and deletion at the end.
// Vector Reference:
// https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/
// https://en.cppreference.com/cpp/container/vector
// Dynamic Memory Allocation Reference:
// https://www.geeksforgeeks.org/cpp/what-is-dynamic-memory-allocation/
// Operator Overloading Reference:
// https://www.geeksforgeeks.org/cpp/operator-overloading-cpp/
// Initializer List Reference:
// https://en.cppreference.com/cpp/utility/initializer_list

// TODO: PRECISO IMPLEMENTAR .begin(), .end() SEM ELES FODEU
//       PRECISO ENTENDER BEM ITERADORES DO CPP SEM ELES FODEU

#include <initializer_list>
#include <iterator>

namespace Lists
{
    template <typename T>
    class Vector
    {
        public:
            Vector()
            {
                this->head = nullptr;
                this->size = 0;
                this->capacity = 0;
            }

            // TENTAR IMPLEMENTAR ISSO DPS DE TER .begin() e .end()
            // Vector(std::initializer_list<T> l)
            // {
            //     this->size = l.size();
            // }

            T& operator [](int index)
            {
                return head[index];
            }

            T operator [](int index) const
            {
                return head[index];
            }

            void push_back(T e)
            {
                if (this->size + 1 <= this->capacity)
                {
                    this->head[++this->size] = e;
                    this->capacity++;
                    return;
                }

                auto temp = new T[++this->capacity];
            }

        private:
            T *head;
            std::size_t size, capacity;
    };
}

#endif
