#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+7;
const int M=5e5+7;
vector<pair<int,int>>edge[N];
int dis[M];
bool vis[M];
int w[M];
int ww[M];
int k[N];
int a[N][M],t[N][M];
void dij(int s){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push(make_pair(ww[s],s));
    dis[s]=0;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<(int)edge[u].size();i++){
            int v=edge[u][i].first;
            int www=edge[u][i].second;
            if(dis[v]>dis[u]+www+ww[u]){
                dis[v]=dis[u]+www+ww[u];
                if(!vis[v]){
                    q.push(make_pair(dis[v],v));
                }
            }
        }
    }
}
vector<int>v;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,n,m,d,q;cin >>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin >>w[i];
    }
    for(int i=1;i<=n;i++){
        cin >>k[i];
        for(int j=1;j<=k[i];j++){
            cin >>a[i][j]>>t[i][j];
            if(j!=1){
                edge[a[i][1]].push_back(make_pair(a[i][j],t[i][j]));
                edge[a[i][j]].push_back(make_pair(a[i][1],t[i][j]));
            }
        }
        ww[i]=t[i][1];
    }
    while(q--){
        int x,y;cin >>x>>y;
        dij(x);
        // cout<<dis[y]<<"\n";
        cout<<dis[y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/