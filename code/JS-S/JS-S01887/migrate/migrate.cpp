#include<bits/stdc++.h>
using namespace std;
#define llo long long
const int N=2e6+10;
llo c,t,n,d,x[N];
llo dis[502][502],minn[502][502],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
            ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",&x[i]);
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=n;i++)
            dis[i][i]=0;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if((llo)(x[j]-x[i])<=d){
                minn[i][j]=1;
                dis[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==j)continue;
            for(int p=i+1;p<=j;p++){
                if(i==p||j==p)continue;
                if(dis[i][p]+dis[p][j]<dis[i][j]){
                    dis[i][j]=dis[i][p]+dis[p][j];
                    minn[i][j]=1;
                }
                else
                if(dis[i][p]+dis[p][j]==dis[i][j])
                    minn[i][j]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(minn[i][j]==2)
            ans++;
    printf("%lld\n",ans);
    }
    return 0;
}
