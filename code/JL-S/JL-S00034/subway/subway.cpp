#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int c,n,m,d,q;
struct point{
    int v,t;
    bool operator<(const point &x)const{
        return t<x.t;
    }
};
int w[M],t[M][M];
vector<int> adj[M];
int dijiesitela(int x,int y){
    priority_queue<point> q;
    q.push({x,0});
    while(!q.empty()){
        int u=q.top().v,now=q.top().t;
        q.pop();
        if(u==y)return now;
        for(auto v:adj[u]){
            q.push({v,now+w[u]+w[v]+2*t[v][u]});
        }
    }
    return -1;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a;
            cin>>a>>t[i][j];
            t[j][i]=t[i][j];
            adj[i].push_back(j);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dijiesitela(x,y)<<endl;
    }
    return 0;
}
