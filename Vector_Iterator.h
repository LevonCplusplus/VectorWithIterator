#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
template <class T>
class Vector{
    T * m_data;
    size_t m_size;
    size_t m_capacity;
    void reallocate(size_t capacity);
public:
    class const_iter{
    protected:
        const T* m_ptr;
    public:
        const_iter()= default;
        explicit const_iter(T* ptr):m_ptr(ptr){};
        const_iter(const const_iter& other){
            m_ptr = other.m_ptr;
        }
        const_iter(const_iter&& other){
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        const_iter& operator=(const const_iter& other){
            if(&other != this){
                m_ptr = other.m_ptr;
            }
            return *this;
        }
        const_iter& operator=(const_iter&& other){
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
            return *this;
        }
    

        std::ptrdiff_t operator-(const const_iter& other)const{
            return (other.m_ptr - this -> m_ptr);
        }
        const_iter operator+(std::ptrdiff_t n)const{
            return const_iter(this -> m_ptr + n);
        }
        const_iter operator-(std::ptrdiff_t n)const{
            return const_iter(this -> m_ptr - n);
        }
        const_iter& operator+=(std::ptrdiff_t n){
            m_ptr += n;
            return *this;
        }
        const T& operator*(){
            return *m_ptr;
        }
        const_iter& operator++(){
            ++m_ptr;
            return *this;
        }
        bool operator!=(const const_iter& other){
            return other.m_ptr != this->m_ptr;
        }
        const_iter operator++(int){
            const T* tmp = m_ptr++;
            return const_iter(tmp); 
        }

        virtual ~const_iter() = default;
    };
    class iterator:public const_iter{
    public:
        using const_iter::const_iter;
          

        T& operator*() {
            return const_cast<T&>(const_iter::operator*());
        }

        const T& operator*() const {
            return const_iter::operator*();
        }

        iterator& operator++() {
            const_iter::operator++();
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator!=(const iterator& other) const {
            return this->m_ptr != other.m_ptr;
        }
    };

    Vector();
    Vector(const Vector &);
    ~Vector();
    T& at (size_t index);
    T& operator[](size_t n);
    template <typename P>
    void push_back(P &&);
    void pop_back();
    size_t get_Size();
    size_t get_Cap();
    void resize(size_t size);
    void reserve(size_t capacity);
    T front()const;
        T back()const;
        const_iter cbegin(){
        return const_iter(m_data);
    }
    const_iter cend(){
        return const_iter(m_data + m_size);
    }
    iterator begin(){
        return iterator(m_data);
    }
    iterator end(){
        return iterator(m_data + m_size);
    }

    bool is_empty()const;
    void shrink_to_fit(); 
    void insert(size_t index,T & value);
    void erase(size_t index); 
    void clear();
    
};
#include "Vector_Iterator.tpp"
#endif