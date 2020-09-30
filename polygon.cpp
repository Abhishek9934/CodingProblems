#include<bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
};

bool onSegment(point p, point q, point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
       return false; 
} 

int checkOrientation(point p , point q , point r)
{
    int temp = (q.y - p.y) * (r.x- q.x) - (q.x - p.x)*(r.y - q.y);
    if(temp == 0 )
     return 0; // colinear
     if(temp < 0 )
     return 2; 
     return 1; 
}

bool checkIntersection(point a , point b, point c ,point d)
{
int o1 = checkOrientation(a,b,c);
int o2 = checkOrientation(a,b,d);
int o3 = checkOrientation(c,d,a);
int o4 = checkOrientation(c,d,b);
if (o1 != o2 && o3 != o4) 
 return true; 
if (o1 == 0 && onSegment(a, c, b)) 
 return true; 
if (o2 == 0 && onSegment(a, d, b)) 
 return true; 
if (o3 == 0 && onSegment(c, a, d))
 return true; 
if (o4 == 0 && onSegment(c, b, d))
 return true; 
return false; 
}
bool checkInside(point polygon[] ,int n , point p)
{
 
 if(n <= 2)
 return false;

point infy = {INT_MAX , p.y};

int c = 0 ; int i  = 0;
do
{
 int next = (i+1) % n;
 if(checkIntersection(polygon[i] , polygon[next] , p , infy))
 {
    if(checkOrientation(polygon[i] , p , polygon[next]) == 0)
     {
         if(onSegment(polygon[i], p , polygon[next]))
         return true;
         else
         return false;
     }
    c++;
 }
    
 i = next;

}while(i!=0);


if(c % 2 != 0)
return true;
else
return false;

}

int main()
{
 int n;
 cout<< " Enter the number of vertices of polygon\n";
 cin>> n;
 cout<< " Enter coordinates x and y of the polygon \n";
 point polygon[n];
 for(int i = 0 ;i<n ;i++)
 { 
   cin>> polygon[i].x >> polygon[i].y;
 }
point p;
 cout<< " enter point to checked\n";
 cin>> p.x>>p.y;

 if(checkInside(polygon ,n,  p))
 cout<< "Point is inside the polygon\n";
 else
 cout<< "Point lies outside the polygon\n";

 return 0;
}