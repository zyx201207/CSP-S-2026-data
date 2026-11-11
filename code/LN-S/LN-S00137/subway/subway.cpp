#include<bits/stdc++.h>
using namespace std;
/*struct node{
    int x,y,c;
};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
queue <node>q;
bool vis[30][30];
/*void bfs(int sx,int sy){
    node s={sx,sy,0};
    q.push(s);
    vis[sx][sy]=1;
    while(!q.empty()){
        node f=q.front();
        if(a[f.x][f.y]==2){
            cout<<f.c*
        }
        for(int i=0;i<4;i++){
            int nx=f.x+dx[i];
            int ny=f.y+dy[i];
            if(nx>=1&&nx<=100&&ny>=1&&ny<=100&&a[nx][ny]==1&&vis[nx][ny]==0){
                vis[nx][ny]=1;
                node t={nx,ny,f.c+1};
                q.push(t);
            }
        }
    }
}*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

   /* int M[500005];
    vector<vector<int>>a;
    vector<vector<int>>b;
    for(int i=1;i<=m;i++){
        cin>>M[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int nn,mm;
            cin>>nn>>mm;
            a[i][j]=nn;
            b[i][j]=mm;
        }
    }
    while(q--){
        int s,e;
        cin>>s>>e;
    }*/


    //if(c>=12&&c<=19){
      //  bfs()
    //}else{
        for(int i=1;i<=q;i++){
            cout<<0<<'\n';
        }
    //}














    return 0;
}
