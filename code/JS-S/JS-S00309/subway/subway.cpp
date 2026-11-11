#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,x,y,m,d,q,K,w[500005],f[505][505];
vector<int>a[505],t[505];
vector<pair<int,int>>dot[500005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++){
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>K;
        for(int j=1;j<=K;j++){
            cin>>x;
            a[i].push_back(x);
            cin>>y;
            t[i].push_back(y);
            dot[x].push_back({i,y});
        }
    }
    //for(int i=1;i<=m;i++){
     //   dot[i].push_back({0,0});
    //}
    for(int i=1;i<=m;i++){
        for(auto k:dot[i]){
            for(auto p:dot[i]){
                if(k.first!=p.first){
                    f[k.first][p.first]=min(f[k.first][p.first],k.second+p.second);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][k]<1e18&&f[k][j]<1e18){
                    f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
                }
            }
        }
    }
    while(q--){
        cin>>x>>y;
        int ans=1e18;
        for(auto k:dot[x]){
            for(auto p:dot[y]){
                int ji=w[x]+w[y];
                ji+=(k.second+p.second+f[k.first][p.first]);
                ans=min(ans,ji);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
