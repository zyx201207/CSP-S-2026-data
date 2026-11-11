#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;long long dp[505][505],w[505],a[505],t[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i==j){
                continue;
            }
            dp[i][j]=0x3f3f3f3f3f3f3f3f;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%lld %lld",&a[j],&t[j]);
        }
        for(int j=1;j<=k;j++){
            for(int jk=1;jk<=k;jk++){
                if(dp[a[j]][a[jk]]>t[j]+t[jk]){
                    dp[a[j]][a[jk]]=t[j]+t[jk];
                }
            }
        }
    }
    for(int jk=1;jk<=m;jk++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(dp[i][jk]+dp[jk][j]<dp[i][j]){
                    dp[i][j]=dp[i][jk]+dp[jk][j];
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d %d",&n,&m);
        printf("%lld\n",dp[n][m]+w[n]+w[m]);
    }

    return 0;
}
