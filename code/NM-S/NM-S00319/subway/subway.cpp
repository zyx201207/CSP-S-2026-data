#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=510;
int n,m,q,w[N],cnt[N],t[N][20],id[N][20];
long long dist[M][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&n,&n,&m,&q,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        int c,x,y;
        scanf("%d",&c);
        while(c--){
            scanf("%d%d",&x,&y);
            id[x][cnt[x]]=i;
            t[x][cnt[x]]=y;
            ++cnt[x];
        }
    }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++) dist[i][j]=dist[j][i]=1e18;
    for(int i=1;i<=m;i++){
        for(int j=0;j<cnt[i]-1;j++){
            for(int k=j+1;k<cnt[i];k++){
                if(t[i][j]+t[i][k]<dist[id[i][j]][id[i][k]]){
                    dist[id[i][j]][id[i][k]]=dist[id[i][k]][id[i][j]]=t[i][j]+t[i][k];
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(i==k || dist[i][k]==1e18) continue;
            for(int j=1;j<=n;j++){
                if(dist[k][j]==1e18) continue;
                if(dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    while(q--){
        int x,y;
        long long ans=1e18;
        scanf("%d%d",&x,&y);
        for(int i=0;i<cnt[x];i++){
            for(int j=0;j<cnt[y];j++){
                long long les=dist[id[x][i]][id[y][j]]+w[x]*1ll+w[y]*1ll+t[x][i]*1ll+t[y][j]*1ll;
                if(ans>les) ans=les;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
