#include <bits/stdc++.h>
#define int long long
#define pii pair <int,int>
#define MP make_pair
#define fi first
#define se second
using namespace std;

namespace annika{
    const int N=503,M=5e5+3;
    int c,n,m,d,q,w[M],p;
    int u[N][N];
    vector <pii> a[M];
    
    void main(){
        cin>>c>>n>>m>>d>>q;
        for (int i=1;i<=m;i++){
            cin>>w[i];
        }
        for (int i=1;i<=n;i++){
            int t;
            cin>>t;
            for (int j=1;j<=t;j++){
                int A,T; cin>>A>>T;
                a[A].emplace_back(MP(i,T));
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                u[i][j]=1e18;
            }
        }
        for (int i=1;i<=n;i++) u[i][i]=0;
        for (int A=1;A<=m;A++){
            int len=a[A].size();
            for (int j=0;j<len;j++){
                for (int k=0;k<j;k++){
                    if (a[A][j].se+a[A][k].se<u[a[A][j].fi][a[A][k].fi])
                        u[a[A][j].fi][a[A][k].fi]=u[a[A][k].fi][a[A][j].fi]=a[A][j].se+a[A][k].se;
                }
            }
        }
        for (int k=1;k<=n;k++){
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    u[i][j]=min(u[i][j],u[i][k]+u[k][j]);
                }
            }
        }
        while (q--){
            int x,y; cin>>x>>y;
            int ans=1e18;
            for (auto xx:a[x]){
                for (auto yy:a[y]){
                    ans=min(ans,xx.se+yy.se+u[xx.fi][yy.fi]);
                }
            }
            ans+=w[x]+w[y];
            cout<<ans<<"\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    annika::main();

    return 0;
}