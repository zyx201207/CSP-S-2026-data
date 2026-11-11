#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,t;
const int N=1000000;
int w[N];
int l[20001][20001];
struct node{
    int a,t;
};
struct node2{
    int aa,bb,cc;
};
vector<node> e[N];
vector<int>f[N];
bool vis[20001][500];
void solve(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){

            }
        }
    }


}
int bfs(int xx,int y){
    memset(vis,0,sizeof(vis));
    queue<node2> q;
    while(q.size())q.pop();
    node2 aa;
    for(auto s:f[xx]){
    aa.aa=s;
    aa.bb=xx;
    aa.cc=w[xx]+t;
        vis[xx][s]=1;
        //cout<<s;
        q.push(aa);
    }
    while(!q.empty()){
        node2 u=q.front();
        q.pop();
        if(u.bb==y){
            return u.cc+w[y]+t;
        }
        int x=u.bb,s=u.aa,c=u.cc;
        vis[x][s]=1;
        q.pop();
        for(auto v:e[s]){
            if(vis[v.a][s])continue;
            //cout<<v.a;
            aa.aa=s;
            aa.bb=v.a;
            aa.cc=c;
            q.push(aa);
            //q.push({s,v.a,c});
        }
        for(auto v:f[u.bb]){
            if(vis[x][v])continue;
            //cout<<x;
            aa.aa=v;
            aa.bb=x;
            aa.cc=c+2*t;
            q.push(aa);
        }
    }
    return -1;
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int x,y,k;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>x>>y;
            t=y;
            e[i].push_back({x,y});
            f[x].push_back(i);
        }
    }
    int xx,yy;
    for(int i=0;i<p;i++){
        cin>>xx>>yy;
        cout<<bfs(xx,yy);
    }
    return 0;
}
/*
1 2 6 6 3
1 2 3 4 5 6
4 1 1 2 1 3 1 4 1
3 4 1 5 1 6 1

*/
