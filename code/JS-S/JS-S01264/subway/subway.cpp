#include<bits/stdc++.h>
using namespace std;
struct stat{
    int a,t;
}G[501][200005];
int c,n,m,d,q;
int w[200005];
int k[501];
int st,ed;
vector<pair<int,int>>sta[200005];
bool vis[200005];
int ans=INT_MAX;
void dfs(int l,int u,int ed,int cost){
    if(vis[u])return;
    //printf("l:%d u:%d ed:%d cost:%d\n",l,u,ed,cost);
    if(u==ed){
        ans=min(ans,cost);return;
    }
    vis[u]=1;
    for(auto i:sta[u]){
        for(int j=1;j<=k[i.first];j++){
            if(G[i.first][j].a==u)continue;
            if(i.first==l)dfs(l,G[l][j].a,ed,cost+G[l][j].t);
            else dfs(i.first,G[i.first][j].a,ed,cost+i.second+G[i.first][j].t);
        }
    }
    vis[u]=0;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>G[i][j].a>>G[i][j].t;
            sta[G[i][j].a].push_back({i,G[i][j].t});
        }
    }
    while(q--){
        cin>>st>>ed;
        ans=INT_MAX;
        for(auto i:sta[st]){
            dfs(i.first,st,ed,i.second);
        }
        cout<<ans+w[st]+w[ed]<<'\n';
    }
}