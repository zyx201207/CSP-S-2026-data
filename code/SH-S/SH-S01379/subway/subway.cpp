#include<bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("subway.in");
ofstream fout("subway.out");
#define cin fin
#define cout fout
using pi=pair<int,int>;
const int N=505,M=5e5+5,inf=1e18;
int c,n,m,d,q,w[M],dis[N][N];
vector<pi> pass[M];
signed main() {
    // auto st=clock();
    // ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) {
        int len; cin>>len;
        while(len--) {
            int u,w; cin>>u>>w;
            pass[u].push_back({i,w});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=inf;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(auto [u,w1]:pass[i])
            for(auto [v,w2]:pass[i])
                dis[u][v]=min(dis[u][v],w1+w2);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--) {
        int s,t; cin>>s>>t;
        int mn=inf;
        for(auto [u,w1]:pass[s])
            for(auto [v,w2]:pass[t])
                mn=min(mn,w1+w2+dis[u][v]);
        cout<<mn+w[s]+w[t]<<'\n';
    }
    // auto ed=clock();
    // cerr<<fixed<<setprecision(3)<<1000.0*(ed-st)/CLOCKS_PER_SEC<<" ms\n";
}