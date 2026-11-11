#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef unsigned long long ll;

const int N=500005,M=505;
const ll inf=1e18;
int c,n,m,d,q,w[N];
ll f[M][M];
vector<PII>e[N];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            e[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        f[i][i]=0;
        for(int j=i+1;j<=n;j++)
            f[i][j]=f[j][i]=inf;
    }
    for(int o=1;o<=m;o++){
        int T=e[o].size();if(T<=1)continue;
        for(int i=0;i<T;i++)for(int j=i+1;j<T;j++){
            int x=e[o][i].first,y=e[o][j].first;
            int v=e[o][i].second+e[o][j].second;
            if(v<f[x][y])f[x][y]=v;
        }
    }
    for(int x=1;x<=n;x++)for(int y=1;y<=n;y++){
        if(f[x][y]>f[y][x])f[x][y]=f[y][x];
        else f[y][x]=f[x][y];
    }
    for(int k=1;k<=n;k++){
        ll*g=f[k];
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            f[i][j]=min(f[i][j],f[i][k]+g[j]);
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;ll ans=inf;
        for(auto[t1,y1]:e[x])for(auto[t2,y2]:e[y])
            ans=min(ans,f[t1][t2]+y1+y2);
        cout<<ans+w[x]+w[y]<<'\n';
    }
}
