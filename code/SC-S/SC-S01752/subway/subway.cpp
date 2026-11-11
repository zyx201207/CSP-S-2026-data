#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=510,inf=0x3f3f3f3f3f3f3f3f;
int w[N],f[M][M];
vector<pair<int,int>> ht[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){  
        int k;scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            int a,t;scanf("%lld%lld",&a,&t);
            ht[a].push_back(make_pair(i,t));
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto x:ht[i]){
            for(auto y:ht[i]) if(x.first!=y.first){
                int u=x.first,v=y.first,a=x.second,b=y.second;
                f[u][v]=min(a+b,f[u][v]);
                f[v][u]=min(a+b,f[v][u]);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y;scanf("%lld%lld",&x,&y);
        int ans=inf;
        for(auto p:ht[x]){
            for(auto q:ht[y]){
                int u=p.first,v=q.first,a=p.second,b=q.second;
                ans=min(ans,w[x]+a+f[u][v]+b+w[y]);
            }
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}