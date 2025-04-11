#pragma once
#include <cmath>

template<class T>
class Vec2 {
    private:
        T x, y; // Just x and y
    public:
        // Constructors.
        Vec2() {x, y = 0;}
        Vec2(T xvalue, yvalue) {
            x = xvalue;
            y = yvalue; // Easy-peasy.
        }
        // Set and get.
        void Set(const T &xvalue, const T &yvalue) {
            x = xvalue;
            y = yvalue;
        }
        T GetX() const {return xvalue;}
        T GetY() const {return yvalue;}
        
        void SetX(const T &xvalue) const {x = xvalue;}
        void SetY(const T &yvalue) const {y = yvalue;}

        // Helper and utility methods.
        void Zero() {x = y = z = 0;}
        void Normalize() {
            T magnitude = sqrt(x**2 + y**2);

            if (magnitude != 0) {
                x /= magnitude;
                y /= magnitude;
            }
            else {
                return Zero();// Math error: Cannot divide by zero, so return a zero vector.
            }
        }
        // Dot products and vector products.
        // Usage: static foo = Vec2::DotProduct(vectorA, vectorB);
        static T DotProduct2D(const Vec2 &a, const Vec2 &b) {
            return a.x * b.x + a.y * b.y;
        }
        T DotProduct2D(const Vec2 &b) const {
            return x * b.x + y * b.y;
        }
        static T CrossProduct2D(const Vec2 &a, const Vec2 &b) {
            return (a.y * b.x - a.x * b.y);
        }
        T CrossProduct2D(const Vec2 &b) const {
            return (y * b.x - x * b.y);
        }
        void AddX(T value) { x+= xvalue;}
        void AddY(T value) { y+= yvalue;}
        void SubX(T value) { x-= xvalue;}
        void SubY(T value) { y-= yvalue;}
        
        // TODO: #1 Distances and angles.

        // Now for the juicy stuff: OPERATUR OVERLODE! (fire band name ngl)

};
