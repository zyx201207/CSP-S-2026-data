#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+500;
const ll inf=1e18;
mt19937 rad((0xC3+0xC5)>>1);
void upt(ll&a,ll b){a=min(a,b);}
int c,n,m,D,Q;ll w[M];
struct edge{int u;ll w;};
vector<edge>g[M];
ll d[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>D>>Q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k,a,t;i<=n;i++){
        for(cin>>k;k--;)cin>>a>>t,g[a].push_back({i,t});
    }
    for(int i=1;i<=n;i++)fill(d[i]+1,d[i]+n+1,2*inf),d[i][i]=0;
    for(int i=1;i<=m;i++){
        for(size_t p=0;p<g[i].size();p++){
            auto[u1,w1]=g[i][p];
            for(size_t q=p+1;q<g[i].size();q++){
                auto[u2,w2]=g[i][q];
                upt(d[u1][u2],w1+w2);
                upt(d[u2][u1],w1+w2);
            }
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)upt(d[i][j],d[i][k]+d[k][j]);
    for(int qid=1,x,y;qid<=Q;qid++){
        cin>>x>>y;ll ans=inf;
        for(size_t p=0;p<g[x].size();p++){
            auto[u1,w1]=g[x][p];
            for(size_t q=0;q<g[y].size();q++){
                auto[u2,w2]=g[y][q];
                upt(ans,d[u1][u2]+w1+w2);
            }
        }cout<<w[x]+w[y]+ans<<"\n";
    }
    cout.flush();
    return 0;
}