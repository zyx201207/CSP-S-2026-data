#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM=5e5+10;
const int MAXD=25;
const int MAXN=510;
const int INF=1e18;
int c,n,m,d,q,K,a,x,y,ans,t;
struct edge{
    int v,w;
};
vector<edge> v[MAXM];
int w[MAXM];
int dis[MAXN][MAXN];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=INF;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>K;
        for(int j=1;j<=K;j++){
            cin>>a>>t;
            v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
        for(edge j:v[i])
            for(edge k:v[i])
                dis[j.v][k.v]=min(dis[j.v][k.v],j.w+k.w);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
            }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans=INF;
        for(edge j:v[x])
            for(edge k:v[y])
                ans=min(ans,dis[j.v][k.v]+j.w+k.w);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
//g++ subway.cpp -o subway -std=c++14 -O2 -static -Wall -Wextra -Wshadow
//ulimit -v
//ulimit -s
//time ./subway