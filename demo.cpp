#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>

using namespace std;

//int maxi = 100;
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
        for (int j = 0; j < path[0].size(); j++)
        {
            if(path[i][j] == 1){
                weights[i][j] = 0;
                visited[i][j] = 0;
            }   
        } 
    } 
}

vector<int> algo()
{
   // read the input txt
   //create weights vector, set all possible to zero
       //two step algorithm
   //find the highest and not visited
   int maxi = 100;
   int max_row = 0;
   int max_col = 0;

   for(int i=0; i<path.size(); i++)
   {
      for(int j=0; j<path[0].size(); j++)
      {
         if(path[i][j])
         {
            if ( (weights[i][j]>maxi || maxi==100) && (!visited[i][j]) )
            {
               maxi = weights[i][j];
               max_row = i;
               max_col = j;
            }
         }
      }
   }
    //cout<<max_row<<max_col<<endl;
    return vector<int>{max_row, max_col};
}

void neighbours(int i, int j)
{
   visited[i][j] = 1;
   //cout<<i<<j<<endl;
   direction[weights[i][j]] = pair<int,int>(i,j);
   for(int x=-1; x<=1; x+=2)
   {  //todo check if the current weight is higher
      if (i+x>=0 && i+x<5 && path[i+x][j] && !visited[i+x][j])
      {
         weights[i+x][j] = weights[i][j] + 1;
         //direction[weights[i+x][j]] = pair<int,int>(i+x,j);
      }
      if (j+x>=0 && j+x<7 && path[i][j+x] && !visited[i][j+x])
      {
         weights[i][j+x] = weights[i][j] + 1;
         //direction[weights[i][j+x]] = pair<int,int>(i,j+x);
      }
   }
   //cout<<"done"<<endl;
}
   
   
bool check(vector<vector<int>> v)
{
    for (int i=0; i<5; i++){
        for (int j = 0; j < 7; j++) {
            if (path[i][j] == 1 && visited[i][j] ==0) {
                return false;
            }
        }
    }
    return true;
}
   
void printvector(vector<vector<char>> v){
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}

vector<vector<char>> back_track(vector<vector<int>> v)
{
    vector<int> maxe;
    vector<vector<char>> fin;
    vector<char> w(v[0].size(), '#');
    for (int i = 0; i < 5; i++){
        fin.push_back(w);
    }
    //find the max element
    for (int i = 0; i < v.size(); i++) {
        maxe.push_back(*max_element(v[i].begin(), v[i].end()));
    }
    int emax = *max_element(maxe.begin(), maxe.end());

/*    row = ((*direction.find(7)).second).first;
    col = ((*direction.find(7)).second).second;
    cout<<row<<"what"<<col;
*/    
    while (emax >= 0)
    {
        row = ((*direction.find(emax)).second).first;
        col = ((*direction.find(emax)).second).second;
        fin[row][col] = '0' + emax;
        cout<<emax<<endl;
        emax --;
    }
   
    return fin;
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
    set_all();
    
    vector<int> pos ;
/*  
    pos = algo();
    neighbours(pos[0], pos[1]);
    printvector(weights);
    pos = algo();
    neighbours(pos[0], pos[1]);
    printvector(weights);
    pos = algo();
    neighbours(pos[0], pos[1]);
    printvector(weights);

    pos = algo();
    neighbours(pos[0], pos[1]);
    printvector(weights);
    printvector(visited);
    //cout<<"visited"<<endl;
    //printvector(visited);
    //cout<<"weights"<<endl;
    //printvector(weights);
 */
    bool done = false;
    while (! done)
    {
        //find heighst not visited
        vector<int> pos = algo();    
        // assign neighbours
        neighbours(pos[0], pos[1]);
        done = check(visited);
        //cout<<done<<endl;
    }
    
    //printvector(weights);
    //back_track(weights);
    vector<vector<char>> f = back_track(weights);
    printvector(f);

    return 0;

}
