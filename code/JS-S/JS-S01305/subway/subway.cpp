#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005];
int k[500005];
int t[500005][505];
vector<int> g[500005];
int f[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) f[i][j]=1e18;
    }for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int v,x;
            cin>>v>>x;
            g[v].push_back(i);
            t[v][i]=x;
        }
    }for(int i=1;i<=m;i++){
        for(auto l : g[i]){
            for(auto r : g[i]){
                if(l!=r){
                    f[l][r]=t[i][l]+t[i][r];
                    f[r][l]=t[i][l]+t[i][r];
                }
            }
        }
    }for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }while(q--){
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for(auto i : g[x]){
            for(auto j : g[y]){
                ans=min(ans,t[x][i]+f[i][j]+t[y][j]);
            }
        }cout<<w[x]+w[y]+ans<<"\n";
    }
    return 0;
}
