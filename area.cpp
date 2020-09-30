#include<bits/stdc++.h>
using namespace std;
struct point
{
    float x;
    float y;
};
bool comp(point *a , point *b )
{
    return a[0].x < b[0].x;
}

float solve(point buildings[][4] , int n, point s)
{
    float ans = 0.0;
    

    // sort(buildings , buildings + n ,comp);
    
    ans += (buildings[0][0].y - buildings[0][1].y);
    // cout<< ans <<"kjdjd";
    float maxht = s.y;
    int f = 0 ;
    //first covering the length in the roof top of each building
    for(int i = 0 ;i < n-1 ;i++ )
    {
        float curr_y = buildings[i][0].y;
        if(curr_y > maxht)
         {
        f =1;
         break;
         }
        ans += abs(buildings[i][0].x - buildings[i][3].x);
        // ans += abs(buildings[i+1][1].y - buildings[i][0].y) - 
        float extradistance = (buildings[i+1][1].x - buildings[i][2].x) * (s.y - buildings[i][3].y) /(s.x  - buildings[i][3].x );

        extradistance = min(extradistance , buildings[i+1][0].y - buildings[i+1][1].y );

        if(buildings[i+1][0].y >= buildings[i][0].y)
        {
           ans += (buildings[i+1][0].y - buildings[i][3].y) + ( extradistance  );
        }
        else
        { 
           ans += extradistance - (curr_y - buildings[i+1][0].y );
        }

    }
 // include the last roof 
  if(f == 0)
  {
      ans +=abs( buildings[n-1][0].x - buildings[n-1][3].x);
  }
//  cout<<ans << "ljfkj";
 return ans;

}


int main()
{
    int n;
    cout<<"Enter Number of buildings\n";
    cin>> n;
    point buildings[n][4];
    cout<<"Enter the coordinates of the building one by one\n";
    for(int i  = 0 ;i< n;i++)
    {
        for(int j  = 0 ; j< 4 ;j++)
        cin>>buildings[i][j].x >> buildings[i][j].y ;
    }

    cout<< " Enter the coordinates of source of light\n";
    point s;
    cin>>s.x>>s.y;
    cout<< solve(buildings , n , s)<<"\n";

return 0;

}