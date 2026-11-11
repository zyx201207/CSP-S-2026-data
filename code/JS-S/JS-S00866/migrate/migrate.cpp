#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5005,inf=1e18;
int c,t,n,d,s,x[maxn],cnt[maxn][maxn],minx[maxn];
void dfs(int p,int num)
{
    if(p>n) return;
    if(num<minx[p]){
        minx[p]=num;
        cnt[num][p]=1;
    }
    else if(num==minx[p]){
        cnt[num][p]++;
    }
    for(int i=p+1;i<=n;i++){
        if(x[i]-x[p]<=d){
            dfs(i,num+1);
        }
        else{
            return;
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&c,&t);
    while(t--){
        scanf("%lld %lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        s=0;
        for(int i=1;i<=n-3;i++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cnt[i][j]=0;
                }
                minx[i]=inf;
            }
            dfs(i,0);
            for(int j=i+1;j<=n;j++){
                if(cnt[minx[j]][j]==2){
                    s++;
                }
            }
        }
        printf("%lld\n",s);
    }
    return 0;
}
