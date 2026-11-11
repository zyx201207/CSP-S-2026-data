#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005];
vector<pair<int,int> > g[600005];
int f[505][505];

constexpr inline int _min(const int a,const int b){
    return a<b?a:b;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            g[a].push_back({i,t});
           // g[i].push_back({a+n,t});
        }
    }
    memset(f,30,sizeof f);
    for(int i=1;i<=m;i++){
        for(auto u:g[i])
        for(auto v:g[i]){
            if(u.first!=v.first) f[u.first][v.first]=_min(f[u.first][v.first],u.second+v.second);
        }

    }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        f[i][j]=_min(f[i][j],f[i][k]+f[j][k]);
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        int ans=0x7ffffffffffffffll;
        for(auto e1:g[u])
        for(auto e2:g[v]){
            ans=_min(ans,f[e1.first][e2.first]+e1.second+e2.second);
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}/*
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
