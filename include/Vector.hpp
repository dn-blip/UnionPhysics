#ifdef VECTOR_HPP
#define VECTOR_HPP
#include <cmath>

template<typename T>
class Vec2 {
    private:
        T X, Y; // Just x and y components for now.
    public:
        // Constructors.
        Vec2() {X, Y = 0;}
        Vec2(T xvalue, T yvalue) {
            X = xvalue;
            Y = yvalue; // Easy-peasy.
        }
        // Set and get.
        void Set(const T &xvalue, const T &yvalue) {
            X = xvalue;
            Y = yvalue;
        }
        T GetX() const {return X;}
        T GetY() const {return Y;}
        
        void SetX(const T &xvalue) const {X = xvalue;}
        void SetY(const T &yvalue) const {Y = yvalue;}

        // Helper and utility methods.
        void Zero() {X = Y = 0;}
        void Normalize() {
            T magnitude = sqrt((X*X) + (Y*Y));

            if (magnitude != 0) {
                X /= magnitude;
                Y /= magnitude;
            }
            else {
                return Zero();// Math error: Cannot divide by zero, so return a zero vector.
            }
        }
        // Dot products and vector products.
        // Usage: static foo = Vec2::DotProduct(vectorA, vectorB);
        static T DotProduct2D(const Vec2 &a, const Vec2 &b) {
            return a.X * b.X + a.Y * b.Y;
        }
        T DotProduct2D(const Vec2 &b) const {
            return X * b.X + Y * b.Y;
        }
        static T CrossProduct2D(const Vec2 &a, const Vec2 &b) {
            return (a.Y * b.X - a.X * b.Y);
        }
        T CrossProduct2D(const Vec2 &b) const {
            return (Y * b.X - X * b.Y);
        }
        void AddX(T value) { X+= value;}
        void AddY(T value) { Y+= value;}
        void SubX(T value) { X-= value;}
        void SubY(T value) { Y-= value;}
        
        // TODO: #1 Distances and angles.
        
        // Now for the juicy stuff: OPERATUR OVERLODE! (fire band name ngl)

};
template<typename T>
class Vec3 {
    private:
        T X, Y, Z; // Just x, y, z components for now.
    public:
        Vec3() {X, Y, Z = 0;}
        Vec3(T xvalue, T yvalue, T zvalue) {
            X = xvalue;
            Y = yvalue;
            Z = zvalue; // Easy-peasy.
        }
        // Setties and getties.
        void Set(const T &xvalue, const T &yvalue, const T &zvalue) {
            X = xvalue;
            Y = yvalue;
            Z = zvalue;
        }
        T GetX() const {return X;}
        T GetY() const {return Y;}
        T GetZ() const {return Z;}

        void SetX(const T &xvalue) const {X = xvalue;}
        void SetY(const T &yvalue) const {Y = yvalue;}
        void SetZ(const T &zvalue) const {Z = zvalue;}
        // Helper and utility methods.
        void Zero() {X = Y = Z = 0;}
        void Normalize() {
            T magnitude = sqrt((X*X) + (Y*Y) + (Z*Z));

            if (magnitude != 0) {
                X /= magnitude;
                Y /= magnitude;
                Z /= magnitude;
            }
            else {
                return Zero();// Math error: Cannot divide by zero, so return a zero vector.
            }
        }
        // Dot products and vector products.
        // Usage: static foo = Vec3::DotProduct(vectorA, vectorB);
        static T DotProduct3D(const Vec3 &a, const Vec3 &b) {
            return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
        }
        T DotProduct3D(const Vec3 &b) const {
            return X * b.X + Y * b.Y + Z * b.Z;
        }
        static Vec3 CrossProduct3D(const Vec3 &a, const Vec3 &b) {
            return Vec3((a.Y * b.Z - a.Z * b.Y), (a.Z * b.X - a.X * b.Z), (a.X * b.Y - a.Y * b.X));
        }
        Vec3 CrossProduct3D(const Vec3 &b) const {
            return Vec3((Y * b.Z - Z * b.Y), (Z * b.X - X * b.Z), (X * b.Y - Y * b.X));
        }
};
#endif