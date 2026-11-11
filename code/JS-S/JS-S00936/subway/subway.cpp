#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;

const int N=505,M=5e5+5;

int a[M];
vector<pair<int,int>> b[M];
ll g[N][N];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int tc,n,m,d,q;
    scanf("%d%d%d%d%d",&tc,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int k; scanf("%d",&k);
        while(k--){
            int x,y; scanf("%d%d",&x,&y);
            b[x].push_back(make_pair(i,y));
        }
    }
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;i++) g[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<b[i].size();j++) for(int k=j+1;k<b[i].size();k++){
            int u=b[i][j].first,v=b[i][k].first;
            ll w=b[i][j].second+b[i][k].second;
            if(g[u][v]>w) g[u][v]=g[v][u]=w;
        }
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    }
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        ll ans=1e18;
        for(auto [x,t]:b[u]) for(auto [y,t2]:b[v]){
            ans=min(ans,t+g[x][y]+t2);
        }
        printf("%lld\n",ans+a[u]+a[v]);
    }
    return 0;
}
