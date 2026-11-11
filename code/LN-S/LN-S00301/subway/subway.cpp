#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505,M=5e5+10,D=25,inf=0x3f3f3f3f3f3f3f3f;
int zhan[M][D][2],cnt[M];
ll dp[N][N];
int w[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dp,0x3f,sizeof(dp));
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int ki;scanf("%d",&ki);
        for(int j=1;j<=ki;j++){
            int aij,tij;scanf("%d%d",&aij,&tij);
            cnt[aij]++;
            zhan[aij][cnt[aij]][0]=i;
            zhan[aij][cnt[aij]][1]=tij;
        }
    }
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=cnt[i];j++){
            for(int k=1;k<=cnt[i];k++){
                ll sub1=zhan[i][j][0],sub2=zhan[i][k][0],
                    dis=zhan[i][j][1]+zhan[i][k][1];
                if(dp[sub1][sub2]>dis){
                    dp[sub1][sub2]=dis;
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int x=1;x<=k;x++){
            for(int y=1;y<=k;y++){
                if(dp[x][y]>dp[x][k]+dp[y][k]){
                    dp[x][y]=dp[x][k]+dp[y][k];
                }
                if(dp[x][k]>dp[x][y]+dp[y][k]){
                    dp[x][k]=dp[x][y]+dp[y][k];
                }
            }
        }
    }
    for(int r=1;r<=q;r++){
        int xr,yr;scanf("%d%d",&xr,&yr);
        ll ans=inf;
        for(int i=1;i<=cnt[xr];i++){
            for(int j=1;j<=cnt[yr];j++){
                ll sub1=zhan[xr][i][0],sub2=zhan[yr][j][0];
                ll tosub=zhan[xr][i][1]+dp[sub1][sub2]+zhan[yr][j][1];
                if(ans>tosub)ans=tosub;
            }
        }
        printf("%lld\n",ans+w[xr]+w[yr]);
    }
    return 0;
}
