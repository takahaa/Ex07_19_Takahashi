﻿#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :Solid {
private:
    double width;
    double height;
    double depth;

public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetVolume() {
        return width * height * depth;
    }
    double GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }


};

/// <summary>
/// 円柱
/// </summary>
class Cylinder :Solid {
private :
        double radius;
        double height;
public:
    Cylinder(
        double radius,   //半径
        double height){  //高さ
        this->radius = radius;
        this->height = height;
    }
    double GetVolume() {
        return radius * radius * M_PI * height;
    }
    double GetSurface() {
        return radius * radius * M_PI * height + radius * 2 * M_PI * height;
    }

};

/// <summary>
/// 円錐
/// </summary>
class Cone :Solid {
private:
    double radius;
    double height;
public:
    Cone(
        double radius,   //半径
        double height) { //高さ
        this->radius = radius;
        this->height = height;
    }
    double GetVolume() {
        return radius * radius * M_PI * height / 3;
    }
    double GetSurface() {
        return (radius * radius * M_PI + sqrt(radius * radius + height * height)) * radius * M_PI;
    }
};

/// <summary>
/// 球
/// </summary>
class Sphere :Solid {
private:
    double radius;
public:
    Sphere(double radius) { //半径
        this->radius = radius;
    }
    double GetVolume() {
        return M_PI * radius * radius * radius * 1.3;
    }
    double GetSurface() {
        return radius * radius * M_PI * 4;
    }
};



int main()
{
    Box box{ 3,5,2.5 };
    cout << "boxの体積=" << box.GetVolume() << endl;
    cout << "boxの表面積=" << box.GetSurface() << endl;
    Cylinder cylinder{ 2,10.2 };
    cout << "\nCylinderの体積=" << cylinder.GetVolume() << endl;
    cout << "Cylinderの表面積=" << cylinder.GetSurface() << endl;
    Cone cone{ 3.1,5 };
    cout << "\nConeの体積=" << cone.GetVolume() << endl;
    cout << "Coneの表面積=" << cone.GetSurface() << endl;
    Sphere sphere{ 3 };
    cout << "\nSphereの体積=" << sphere.GetVolume() << endl;
    cout << "Sphereの表面積=" << sphere.GetSurface() << endl;
}