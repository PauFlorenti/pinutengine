#pragma once

/*
    @author Pau Florentí Solano
    @version 1.0 15/07/2021

    Purpose: Vector classes for math engine/libraryñ
*/

#include <iostream>
#include <math.h>

namespace mth
{
    template <typename T>
    class vec2
    {
    public:
        T x, y;

        vec2(void) : x(1), y(1) {};
        vec2(T value) : x(value), y(value) {};
        vec2(T x, T y) : x(x), y(y) {};

        float length(void) { return std::sqrt( x*x + y*y ); }
        T sum(void) { return x + y; }

    private:
    };

    /**
     *  Overloads the operator << to write the value of the vector
     *  @param void
     *  @return beautify the values to be written
     */
    template <class T>
    std::ostream& operator<<(std::ostream& out, const vec2<T>& v)
    {
        return out << "[" << v.x << ", " << v.y << "]";
    }

    /**
     *  Overloads the operator + to apply the sum of two vectors
     *  @param void
     *  @returns the a new vector as a result of the sum
     */
    template <class T>
    vec2<T> operator+(const vec2<T>& a, const vec2<T>& b)
    {
        return vec2<T>( a.x + b.x, a.y + b.y );
    }

    /**
     *  Overloads the operator - to apply the sum of two vectors
     *  @param void
     *  @returns the a new vector as a result of the sum
     */
    template <class T>
    vec2<T> operator - (const vec2<T>& a, const vec2<T>& b)
    {
        return vec2<T>( a.x - b.x, a.y - b.y );
    }

    /**
     * @param constant float
     * @return new vec2 result of the multiplication by constant
     */
    template <class T>
    vec2<T> operator * (const vec2<T>& v, const float a)
    {
        return vec2<T>(v.x * a, v.y * a);
    }

    /**
     *  Vector 3 class
     */

    template <class T>
    class vec3
    {
    public:
        T x, y, z;

        vec3(void) : x(1.0f), y(1.0f), z(1.0f) {};
        vec3(T value) : x(value), y(value), z(value) {};
        vec3(T x, T y, T z) : x(x), y(y), z(z) {};

        T length(void);
    };

    /**
     *  Returns the length of the vector
     *  @param void
     *  @return the length of the vector of type T
     */
    template <class T>
    T vec3<T>::length(void)
    {
        return std::sqrt(x + y + z);
    }

    /**
     *  Overloads the operator << to write the value of the vector
     *  @param void
     *  @return beautify the values to be written
     */
    template <class T>
    std::ostream& operator<<(std::ostream& out, const vec3<T>& v)
    {
        return out << "[" << v.x << ", " << v.y << ", " << v.z << "]";
    }

    /**
     *  Overloads the operator + to apply the sum of two vectors
     *  @param void
     *  @returns the a new vector as a result of the sum
     */
    template <class T>
    vec3<T> operator+(const vec3<T>& a, const vec3<T>& b)
    {
        return vec3<T>( a.x + b.x, a.y + b.y, a.z + b.z );
    }

    /**
     *  Overloads the operator - to apply the sum of two vectors
     *  @param void
     *  @returns the a new vector as a result of the sum
     */
    template <class T>
    vec3<T> operator - (const vec3<T>& a, const vec3<T>& b)
    {
        return vec3<T>( a.x - b.x, a.y - b.y, a.z - b.z );
    }

    /**
     * @param constant float
     * @return new vec2 result of the multiplication by constant
     */
    template <class T>
    vec3<T> operator * (const vec3<T>& v, const float a)
    {
        return vec3<T>(v.x * a, v.y * a, v.z * a);
    }

    template <class T>
    class vec4
    {
    public:
        T x, y, z, w;

        vec4(void) : x(1.0f), y(1.0f), z(1.0f), w(1.0f) {};
        vec4(T value) : x(value), y(value), z(value), w(value) {};
        vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {};

        T length(void);
    };

    /**
     *  Returns the length of the vector
     *  @param void
     *  @return the length of the vector of type T
     */
    template <class T>
    T vec4<T>::length(void)
    {
        return std::sqrt(x + y + z + w);
    }

    /**
     *  Overloads the operator << to write the value of the vector
     *  @param void
     *  @return beautify the values to be written
     */
    template <class T>
    std::ostream& operator<<(std::ostream& out, const vec4<T>& v)
    {
        return out << "[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";
    }

    /**
     *  Overloads the operator + to apply the sum of two vectors
     *  @param void
     *  @returns the a new vector as a result of the sum
     */
    template <class T>
    vec4<T> operator+(const vec4<T>& a, const vec4<T>& b)
    {
        return vec4<T>( a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w );
    }

    /**
     *  Overloads the operator - to apply the sum of two vectors
     *  @param void
     *  @returns the a new vector as a result of the sum
     */
    template <class T>
    vec4<T> operator - (const vec4<T>& a, const vec4<T>& b)
    {
        return vec4<T>( a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w );
    }

    /**
     * @param constant float
     * @return new vec2 result of the multiplication by constant
     * @todo Rethink if instead of float a template could be used (for short, int, double ...)
     */
    template <class T> 
    vec4<T> operator * (const vec4<T>& v, const float a)
    {
        return vec4<T>( v.x * a, v.y * a, v.z * a, v.w * a );
    }
}