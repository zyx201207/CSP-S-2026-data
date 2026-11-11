#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+5;
int c,n,m,d,q,k,a,cnt[M],pos[M][25];//a[N][M],t[N][M]
ll w[M],dis[N][N],ans,t,cost[M][25];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>k;
        fill(dis[i]+1,dis[i]+1+n,(ll)1e18);
        dis[i][i]=0;
        for(int j=1;j<=k;++j){
            cin>>a>>t;cnt[a]++;
            pos[a][cnt[a]]=i;//a第cnt[a]次是在i上出现
            cost[a][cnt[a]]=t;//a第cnt[a]次在i上出现进站的花费为t
        }
    }
    for(int i=1;i<=m;++i)for(int u=1;u<=cnt[i];++u)for(int v=u;v<=cnt[i];++v)dis[pos[i][u]][pos[i][v]]=dis[pos[i][v]][pos[i][u]]=min(dis[pos[i][u]][pos[i][v]],cost[i][u]+cost[i][v]);
    for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=i;j<=n;++j)dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;ans=1e18;
        cin>>x>>y;
        for(int u=1;u<=cnt[x];++u)for(int v=1;v<=cnt[y];++v)ans=min(ans,dis[pos[x][u]][pos[y][v]]+cost[x][u]+cost[y][v]);
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}
/*
O(n^3+m*d^2)
2h30min切了
*/
