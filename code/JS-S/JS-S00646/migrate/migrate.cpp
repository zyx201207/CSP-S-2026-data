#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
const int MAXN=305;
long long dis[MAXN];
unsigned int ans[MAXN][MAXN][2];
void deal(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(abs(i-j)<=1)continue;
            for(int k=2;k<n&&(abs(dis[j]-dis[i])<=d*(ans[i][k][0]+ans[k][j][0]+2)&&(abs(dis[k]-dis[i])<=d*(ans[i][k][0]+1)&&(abs(dis[j]-dis[k])<=d*(ans[k][j][0]+1))));k++){
                if(i==k||j==k)continue;
                if(ans[i][j][0]==ans[i][k][0]+ans[k][j][0]+1)ans[i][j][1]+=ans[i][k][1]*ans[k][j][1];
                if(ans[i][j][0]>ans[i][k][0]+ans[k][j][0]+1){
                    ans[i][j][1]=ans[i][k][1]*ans[k][j][1];
                    ans[i][j][0]=ans[i][k][0]+ans[k][j][0]+1;
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&d);
        memset(ans,0x3f3f3f3f,sizeof(ans));
        for(int i=1;i<=n;i++)scanf("%lld",&dis[i]);
        for(int i=1;i<=n;i++){
            int tmp=0;
            for(int j=i+1;j<=n&&dis[j]-dis[i]<=d;j++){
                ans[i][j][0]=0;
                ans[j][i][0]=0;
                ans[i][j][1]=1;
                ans[j][i][1]=1;
            }
        }
        deal();
        unsigned int cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
                if(ans[i][j][1]==2)cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}