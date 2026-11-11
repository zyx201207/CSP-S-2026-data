#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e6+5;
int c,t;
int n,mn,cnt[N];
ll d,x[N],ans,dp[N];
void check(int l) {
    dp[l]=0,cnt[l]=1;
    for(int i=l+1;i<=n;++i) {
        dp[i]=1e9;
        cnt[i]=0;
    }
    for(int i=l+1;i<=n;++i) {
        for(int j=l;j<i;++j) {
            if(abs(x[i]-x[j])<=d) {
                if(dp[j]+1<dp[i]) {
                    dp[i]=dp[j]+1;
                    cnt[i]=0;
                }
                if(dp[j]+1<=dp[i]) {
                    cnt[i]+=cnt[j];
                    if(cnt[i]>3)cnt[i]=3;
                }
            }
        }
    }
}
void solve() {
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
    ans=0;
    for(int i=1;i<=n;++i) {
        check(i);
        for(int j=i+1;j<=n;++j) {
            if(cnt[j]==2)ans++;
        }
    }
    printf("%lld\n",ans);
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--) {
        solve();
    }
    return 0;
}
