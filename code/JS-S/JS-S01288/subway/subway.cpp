#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<int> a[500005];
vector<int> t[500005];
int f[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(f,0x3f3f3f3f,sizeof(f));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a[x].push_back(i);
            t[x].push_back(y);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<a[i].size();j++){
            for(int k=j+1;k<a[i].size();k++){
                int u=a[i][j],v=a[i][k],w=t[i][j]+t[i][k];
                f[u][v]=min(f[u][v],w);
                f[v][u]=min(f[v][u],w);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)f[i][j]=0;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=1e9;
        for(int i=0;i<a[x].size();i++){
            for(int j=0;j<a[y].size();j++){
                int u=a[x][i],v=a[y][j];
                ans=min(ans,f[u][v]+t[x][i]+t[y][j]);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
