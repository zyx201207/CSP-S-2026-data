#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010];
vector<pair<int,int> >vc[500010];
long long f[510][510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                f[i][j]=1e18;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,x,w;j<=k;j++){
            cin>>x>>w;
            vc[x].push_back({i,w});
        }
    }
    for(int i=1;i<=m;i++)
        for(auto [x,xw]:vc[i])
            for(auto [y,yw]:vc[i])
                f[x][y]=min(f[x][y],1ll*xw+yw);
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         cerr<<i<<' '<<j<<' '<<f[i][j]<<'\n';
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1,u,v;i<=q;i++){
        cin>>u>>v;
        long long res=1e18;
        for(auto [x,xw]:vc[u])
            for(auto [y,yw]:vc[v])
                res=min(res,1ll*w[u]+w[v]+xw+yw+f[x][y]);
        cout<<res<<'\n';
    }
    return 0;
}