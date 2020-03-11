#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

int maxi = 100;
int row = 0;
int col = 0;

map<int, pair<int, int>> direction;
//vector<vector<int>> way;

vector<vector<int>> path;
vector<vector<int>> weights;
vector<vector<int>> visited;

void set_all()
{
    visited = path;
    weights = path;
    for (int i = 0; i < path.size(); i++)
    {
        for (int j = 0; j < path[0].size(); i++)
        {
            if(path[i][j] == 1){
                weights[i][j] == 0;
                visited[i][j] == 0;
            }
            else
            {
                visited[i][j] == 1;
            }
            
        }
        
    }
    
}

int algo()
{
   // read the input txt
   //create weights vector, set all possible to zero
       //two step algorithm
   //find the highest and not visited
   for(int i=0; i<5; i++)
   {
      for(int j=0; j<7; j++)
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
   {  //todo check if the current weight is higher
      if (i+x>=0 && i+x<5 && path[i+x][j] && !visited[i+x][j])
      {
         weights[i+x][j] = weights[i][j] + 1;
         direction[weights[i+x][j]] = pair<int,int>(i,j);
      }
      if (j+x>=0 && j+x<7 && path[i][j+x] && !visited[i][j+x])
      {
         weights[i][j+x] = weights[i][j] + 1;
         direction[weights[i][j+x]] = pair<int,int>(i,j);
      }
   }
}
   
   
bool check(vector<vector<int>> v)
{
    for (int i=0; i<5; i++)
    {
        for (int j = 0; j < 7; j++) {
            if (v[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
   
void printvector(vector<vector<int>> v){
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}

void back_track(vector<vector<int>> v)
{
    /* 
    //todo use this in algo function
    int result = 0;
    vector<int> maxe;
    for (int i = 0; i < 4; i++) {
        result = *max_element(v[i].begin(), v[i].end());
        distance(v[i].begin(), v[i].end());
    }
    //cout<< *max_element(maxe.begin(), maxe.end());
   // distance(weights.begin(),  6);
*/
    maxi = weights[row][col];
    row = ((*direction.find(maxi)).second).first;
    col = ((*direction.find(maxi)).second).first;

    while (maxi != 0)
    {
        row = ((*direction.find(maxi)).second).first;
        col = ((*direction.find(maxi)).second).second;
        path[row][col] = maxi;
        maxi --;
    }
}

vector<vector<int>> read_file(){
    ifstream file("data.txt");
    string line;
    
    vector<int> one;
    vector<vector<int>> way;
    while(getline(file, line)){
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '#')
            {
                one.push_back(0);
            }
            else
            {
                one.push_back(1);
            }
        }
        way.push_back(one);
        one.clear(); 
    }
    return way;
}


int main()
{
    path = read_file();
    //set_all();
    bool done = false;
    /*
    while(!done)
    {
        //find heighst not visited
        algo();
        // assign neighbours
        neighbours(row, col);
        done = check(visited);
    }
    //back_track(weights);
    back_track(weights);
    printvector(path);
    return 0;
*/
}
