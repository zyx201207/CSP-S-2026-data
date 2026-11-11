#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
int w[500010];
int k[505];
struct node{int v,w;};
vector<node> v[500010];
ll dis[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,x,y;j<=k[i];j++){
            cin>>x>>y;
            v[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) dis[i][j]=1e18;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int sz=(int)v[i].size();
        for(int a=0;a<sz;a++)for(int b=0;b<sz;b++){
            dis[v[i][a].v][v[i][b].v]=min(dis[v[i][a].v][v[i][b].v],1LL*v[i][a].w+1LL*v[i][b].w);
        }
    }
    for(int z=1;z<=n;z++)for(int x=1;x<=n;x++)for(int y=1;y<=n;y++)
        dis[x][y]=min(dis[x][y],dis[x][z]+dis[z][y]);
    while(q--){
        int x,y; cin>>x>>y;
        ll ans=1e18;
        for(node &a:v[x])for(node &b:v[y]) ans=min(ans,dis[a.v][b.v]+1LL*a.w+1LL*b.w);
        ans+=1LL*w[x]+1LL*w[y];
        cout<<ans<<'\n';
    }
    return 0;
}