#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstdio>

using namespace std;

typedef pair<int,int> p;
int n,m,map[1001][1001];
int visited[1001][1001][2], di[]={1,-1,0,0}, dj[]={0,0,1,-1};
queue<pair<p,int>> q;

int bfs(){
    q.push({{1,1},0});
    visited[1][1][0]=1;  
    while(!q.empty()){
        pair<p,int> tmp=q.front();
        q.pop();
        int i=tmp.first.first;
        int j=tmp.first.second;
        int block=tmp.second;
        if(i==n && j==m) return visited[i][j][block];
        for(int d=0;d<4;d++){
            int ni=i+di[d], nj=j+dj[d];
            if(ni>n || ni<1 || nj>m || nj<1) continue;
            if(map[ni][nj]){
                if(block) continue;
                visited[ni][nj][1]=visited[i][j][block]+1;
                q.push({{ni,nj},1});
            }
            else if(visited[ni][nj][block]==0){
                visited[ni][nj][block]=visited[i][j][block]+1;
                q.push({{ni,nj},block});
            }
        }
    }
    return -1;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m; 
    cin.ignore();

    for(int i=1;i<=n;i++){
        string str;
        getline(cin,str);

        for(int j=1;j<=m;j++){
            int tmp=str[j-1]-'0';
            map[i][j]=tmp;
            visited[i][j][0]=visited[i][j][1]=0;
        }
    }

    cout<<bfs();

    return 0;
}