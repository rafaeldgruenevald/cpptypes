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
#include <memory>


namespace Lists
{
    template <typename T>
    class Vector
    {
        public:
            Vector()
            {
                this->head = nullptr;
                this->len = 0;
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

            T* begin()
            {
                return head;
            }

            T* end()
            {
                return head + (this->len ? this->len-1 : this->len);
            }

            std::size_t size()
            {
                return this->len;
            }

            bool empty()
            {
                return this->head == nullptr;
            }

            //T* insert(const_iterator pos, const T& value);
            //T* insert(const_iterator pos, T&& value);
            //T* insert(const_iterator pos,
            //              size_type count, const T& value);

            void push_back(T e)
            {
                if (this->len < this->capacity)
                {
                    this->head[this->len++] = e;
                    return;
                }

                // Capacidade vai dobrar sempre que estourar para evitar muitas realocações
                size_t new_capacity = this->capacity ? this->capacity * 2 : 1;

                // unique pointer pra se der throw em algum lugar do codigo abaix
                // (alocacao de memoria, copiar valor de um vetor para o outro) quando
                // a variavel perder a referencia ele ja faz o delete automatico
                std::unique_ptr<T[]> temp(new T[new_capacity]);

                for (size_t i = 0; i < this->len; ++i)
                {
                    temp[i] = this->head[i];
                }

                delete[] this->head;
                // transfere a ownership do vetor pra head (ate parece rust :P)
                this->head     = temp.release();
                this->capacity = new_capacity;

                this->head[this->len++] = e;
            }

            T pop_back()
            {
                // ISSO NAO EH SEGURO, E SE len=0?
                return this->head[--this->len];
            }

            void erase(size_t idx)
            {
                if (idx == (this->len ? this->len-1 : this->len))
                {
                    this->pop_back();
                    return;
                }

                for (size_t i = 0; i < this->len; i++)
                {
                    if (i == idx)
                    {
                        // isso eh seguro ja que o if acima cobre o
                        // caso de ser o ultimo elemento a ser retirado
                        this->head[i] = this->head[++i];
                        continue;
                    }
                    this->head[i] = this->head[i];
                }
                this->len--;
            }
        private:
            T *head;
            std::size_t len, capacity;
    };
}

#endif
