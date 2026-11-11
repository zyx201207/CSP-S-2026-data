#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PLL;
const ll N=505,M=5e5+5,D=25;
const ll INF=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;
ll _w[M];

vector<PLL> g[N+M];
ll dis[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>_w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            g[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(auto [u,w1]:g[i])
            for(auto [v,w2]:g[i])
                dis[u][v]=min(dis[u][v],w1+w2);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    int x,y;
    ll ans,minn;
    while(q--){
        cin>>x>>y;
        ans=_w[x]+_w[y];
        minn=INF;
        for(auto [u,w1]:g[x])
            for(auto [v,w2]:g[y])
                minn=min(minn,w1+w2+dis[u][v]);
        cout<<ans+minn<<"\n";
    }
    return 0;
}