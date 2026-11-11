#include <bits/stdc++.h>
using namespace std;
//final
int w[500005];
int k[505];
int a[505][500005];
int t[505][500005];
int minx=0x3f3f3f3f;
bool f[500005];
vector<pair<int,int>> g[500005];
void dfs(int fa,int y,int ans) {
    f[fa]=true;
    if (fa==y) {
        minx=min(minx,ans);
    }
    for (int i=0;i<g[fa].size();i++) {
        int u=g[fa][i].first;
        int t=g[fa][i].second;
        if (fa!=u&&f[u]==false) {
            //cout<<ans<<" "<<t<<endl;
            dfs(u,y,ans+t);
            f[u]=false;
        }
    }
    return;
}
signed main () {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) {
        cin>>w[i];
    }
    for (int i=1;i<=n;i++) {
        cin>>k[i];
        for (int j=1;j<=k[i];j++) {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for (int i=1;i<=m;i++) {
        int fa=i;
        for (int j=1;j<=n;j++) {
            bool flag=false;
            int pos=0;
            for (int z=1;z<=k[i];z++) {
                if (a[j][z]==fa) {
                    flag=true;
                    pos=z;
                }
            }
            if (flag==false) continue;
            for (int z=1;z<=k[i];z++) {
                if (a[j][z]!=fa) {
                    int s=a[j][z];
                    int tt=t[j][pos]+t[j][z];
                    g[fa].push_back({s,tt});
                }
            }
        }
    }
    int x,y;
    while (q--) {
        minx=0x3f3f3f3f;
        cin>>x>>y;
        dfs(x,y,0);
        cout<<minx+w[x]+w[y]<<endl;
    }
    return 0;
}
