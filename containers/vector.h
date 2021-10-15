#pragma once

namespace cnt
{
    template <class T>
    class Vector
    {
    public:
        Vector(void) = default;

        template <class T>
        void push_back(const T& member)
        {

        }

        T pop_back()
        {

        }

        /**
         * Capacity functions
         */

        int size(void) { return m_size; }
        bool empty();
        void reserve();

        /**
         * Element access
         */

        T at(int position);
        T front();
        T back();

        void erase();

    private:

        T m_type;
        unsigned int m_size;
        int* m_begin;
        int* m_pointer; //pointer to the current last position
        int* m_end;
    };

    template <class T>
    void Vector::push_back(T member)
    {

    }
}