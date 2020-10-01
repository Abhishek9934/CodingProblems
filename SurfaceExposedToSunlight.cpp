/* There is one assumption that I have taken that there are no buildings on the
  left side of the source of light. This code works coorectly for all the buildings
  lying after the x coordinate of the source of light.
 For the buildings lying on the left side of source a similar approch will do,
 but to time constraint I have not implemented it.
*/

#include<bits/stdc++.h>
using namespace std;
struct point
{
    float x;
    float y;
};

void Sort(point buildings[][4], int n)
{
    for(int i = 0;i< n ;i++)
    {
        for(int j = i+1 ; j < n ;j++)
        {
            if(buildings[i][0].x > buildings[j][0].x)
            {
                swap(buildings[i] , buildings[j]);
            }
        }
    }
    
    
}

float solve(point buildings[][4], int n, point s)
{
    float ans = 0.0;
    

    Sort(buildings , n);
    
    ans += (buildings[0][0].y - buildings[0][1].y);
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
        float extradistance = abs(buildings[i+1][1].x - buildings[i][3].x) * abs(s.y - buildings[i][3].y) /abs(s.x  - buildings[i][3].x );

        extradistance = min(extradistance ,abs( buildings[i+1][0].y - buildings[i+1][1].y ));

        if(buildings[i+1][0].y >= buildings[i][0].y)
        {
           ans += abs(buildings[i+1][0].y - buildings[i][3].y) + ( extradistance  );
        }
        else
        { 
           ans += extradistance - abs(curr_y - buildings[i+1][0].y );
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
