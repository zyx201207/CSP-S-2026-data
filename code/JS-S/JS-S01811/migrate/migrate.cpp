#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;
const ll INF=2e18+10;
int c,m,n,t;
ll d,x[N],ans,dp[N];
bool isA,f[N];
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--) {
        ans=0;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++) {
            scanf("%lld",&x[i]);
            if(i>=3&&x[i]-x[i-1]!=x[i-1]-x[i-2]) isA = true;
        }
        if(d >= x[n] - x[1]) {
            printf("0\n");
            return 0;
        }
        if(isA ==false) {
            int k=d/(x[2]-x[1]);
            for(int i=1;i<=n;i++) {
                if(f[i]==true) continue;
                f[i]=true;
                for(int j=i+k;j<=n;j+=k) {
                    ans+=(j-i-k);
                    f[j]=true;
                }
            }
            printf("%lld\n",ans);
        }
        dp[1] = 0;
        dp[2] = 1;
        for(int i=3;i<=n;i++) {
            ll cnt = INF;
            for(int j=i-1;j>=1;j--) {
                if(x[i]-x[j]>d) break;
                if(dp[j] < cnt) {
                    cnt = dp[j];
                    dp[i] = dp[j]+1;
                }
            }
            int sum=0;
            for(int j=i-1;j>=1;j--) {
                if(x[i]-x[j]>d) break;
                if(dp[j] ==cnt ) {
                    sum++;
                }
            }
            if(sum==2) ans++;
        }
        printf("%lld\n",ans+1);
    }
    return 0;
}
