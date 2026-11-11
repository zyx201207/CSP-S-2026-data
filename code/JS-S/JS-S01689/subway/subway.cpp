#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > a[500005];
int w[500005];
long long f[505][505];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    int l,x;
    for(int i=1;i<=n;i++) {
        cin>>l;
        for(int j=1;j<=l;j++) {
            cin>>x>>c;
            a[x].push_back(make_pair(i,c));
        }
    }
    int u,v;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++) {
        for(int j=0;j<a[i].size();j++) {
            for(int k=0;k<j;k++) {
                u=a[i][j].first;
                v=a[i][k].first;
                f[u][v]=min(f[u][v],1ll*a[i][j].second+a[i][k].second);
                f[v][u]=f[u][v];
            }
        }
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i==j||i==k||j==k) continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                f[j][i]=min(f[j][i],f[j][k]+f[k][i]);
            }
        }
    }
    long long ans;
    for(int i=1;i<=q;i++) {
        cin>>u>>v;
        ans=f[0][0];
        for(int j=0;j<a[u].size();j++) {
            for(int k=0;k<a[v].size();k++) {
                ans=min(ans,a[u][j].second+a[v][k].second+f[a[u][j].first][a[v][k].first]);
            }
        }
        cout<<ans+w[u]+w[v]<<"\n";
    }
    return 0;
}