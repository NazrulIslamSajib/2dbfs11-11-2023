#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int vis[100][100];
string arr[10010];
int n,m;
bool isvalid(int a,int b)
{
    return a<n && a>=0 && b<m && b>=0 && arr[a][b]!='#';
}
int main()
{
    cin>>n>>m;
    int i,j;
    memset(vis,-1,10010);
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    /*
    for(i=0;i<n;i++)
    {
         for(j=0;j<arr[i].size();j++)
         {
             cout<<arr[i][j];
         }
         cout<<endl;
    }
    */
    pair<int,int>s,d;
    queue<pair<int,int>>q;
    for(i=0;i<n;i++)
    {
         for(j=0;j<m;j++)
         {
             if(arr[i][j]=='S')
             {
                 s.first=i;
                 s.second=j;
                 vis[s.first][s.second]=0;
                 q.push(s);
             }
             if(arr[i][j]=='D')
             {
                 d.first=i;
                 d.second=j;
             }
         }
    }
    //cout<<q.front().first<<" "<<q.front().second<<endl;//q te source ta niye nilam
      //vis[s.first][s.second]=0;
     //q.push(s);
    //q.push(s);
    while(!q.empty())
    {
        pair<int,int>u;
        u=q.front();
        q.pop();
        for(int k=0;k<4;k++)
        {
            pair<int,int>v;
            v={u.first+dx[k],u.second+dy[k]};
            if(vis[v.first][v.second]==-1 && isvalid(v.first,v.second))
            {
                vis[v.first][v.second]=vis[u.first][u.second]+1;
                q.push(v);
            }
        }
    }
    cout<<"ALL the path"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<vis[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<"DESTINATION  :"<<endl;
    cout<<vis[d.first][d.second]<<endl;



}
/*
3 8
.D.#...#
.S.....S
...S##.#

*/
