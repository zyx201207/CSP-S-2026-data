#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 10004
int C,n,m,D,Q;
int w[maxn],k[maxn];
struct node{
    int v,d;
};
vector<node> v[maxn];
int dot;
int vis[maxn];
int dfs(int u,int r,int d){
    if(u==r){
        if(d!=1e13) d;
        return d;
    }
    int ans=1e13;
    for(auto i:v[u]){
        if(vis[i.v]) continue;
        vis[i.v]=1;
        ans=min(ans,dfs(i.v,r,d+i.d));
        vis[i.v]=0;
    }
    if(ans!=1e13) ans;
    return ans;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>C>>n>>m>>D>>Q;
    dot=m;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        dot++;
        for(int j=1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
            v[dot].push_back({a,t});
            v[a].push_back({dot,t});
        }
    }
    while(Q--){
        int l,r;
        cin>>l>>r;
        memset(vis,0,sizeof(vis));
        vis[l]=1;
        cout<<dfs(l,r,0)+w[l]+w[r]<<endl;
    }
    return 0;
}
