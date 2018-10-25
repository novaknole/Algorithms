//https://www.geeksforgeeks.org/count-integral-points-inside-a-triangle/

// C++ program to find Integral points inside a triangle 
#include<bits/stdc++.h> 
using namespace std; 

/* To find out the area of polygon
Pick's Theeorem:
 A = I + (B/2) -1

A ==> Area of Polygon
B ==> Number of integral points on edges of polygon
I ==> Number of integral points inside the polygon

Using the above formula, we can deduce,
I = (2A - B + 2) / 2 
*/

// Class to represent an Integral point on XY plane. 
class Point { 
    public: 
        int x, y; 
        Point(int a=0, int b=0):x(a),y(b) {} 
}; 
  

int gcd(int a, int b) { 
    if (b == 0) 
       return a; 
    
    return gcd(b, a%b); 
} 
  
 
int getBoundaryCount(Point p,Point q) { 
    
    if (p.x==q.x) 
        return abs(p.y - q.y) - 1; 
    if (p.y == q.y) 
        return abs(p.x-q.x) - 1; 
  
    return gcd(abs(p.x-q.x),abs(p.y-q.y))-1; 
} 
  

int getInternalCount(Point p, Point q, Point r) { 
   int BoundaryPoints = getBoundaryCount(p, q) + 
                         getBoundaryCount(p, r) + 
                         getBoundaryCount(q, r) + 3; 
  
    
    int doubleArea = abs(p.x*(q.y - r.y) + q.x*(r.y - p.y)  + 
                         r.x*(p.y - q.y)); 
  
    return (doubleArea - BoundaryPoints + 2)/2; 
} 
  

int main() { 
    Point p(0, 0); 
    Point q(5, 0); 
    Point r(0, 5); 
    cout << "Number of integral points inside given triangle is "
         << getInternalCount(p, q, r); 
    return 0; 
} 