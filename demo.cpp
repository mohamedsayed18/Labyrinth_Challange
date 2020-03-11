#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxi = 100;
int row = 0;
int col = 0;


vector<vector<int>> path{
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 1, 1, 0},
  {0, 1, 1, 0}
};

vector<vector<int>> weights{
{1, 0, 1, 1},
{1, 0, 0, 1},
{1, 0, 0, 1},
{1, 0, 0, 1}
};

vector<vector<int>> visited{
{1, 0, 1, 1},
{1, 0, 0, 1},
{1, 0, 0, 1},
{1, 0, 0, 1}
};

int algo()
{
   // read the input txt
   //create weights vector, set all possible to zero
       //two step algorithm
   //find the highest and not visited
   for(int i=0; i<4; i++)
   {
      for(int j=0; j<4; j++)
      {
         if(path[i][j])
         {
            if ( (weights[i][j]>maxi || maxi==100) && (!visited[i][j]) )
            {
               maxi = weights[i][j];
               row = i;
               col = j;
            }
         }
      }
      //cout<<row<<col<<endl;
   }
  
}

void neighbours(int i, int j)
{
   visited[i][j] = 1;
   for(int x=-1; x<=1; x+=2)
   {
      if (i+x>=0 && i+x<4 && path[i+x][j] && !visited[i+x][j])
      {
         weights[i+x][j] = weights[i][j] + 1;
      }
      if (j+x>=0 && j+x<4 && path[i][j+x] && !visited[i][j+x])
      {
         weights[i][j+x] = weights[i][j] + 1;
      }
   }
}
   
   
bool check(vector<vector<int>> v)
{
    for (int i=0; i<4; i++)
    {
        for (int j = 0; j < 4; j++) {
            if (v[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
   

void back_track()
{
    
}
int main()
{
    bool done = false;
    while(!done)
    {
        //find heighst not visited
        algo();
        // assign neighbours
        neighbours(row, col);
        done = check(visited);
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << weights[i][j];
        }
        cout << '\n';
    }
    return 0;
}
