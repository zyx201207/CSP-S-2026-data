#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[2000005],dp[2000005],pre[2000005],cnt[2000005];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 2){
        cout << "0\n";
        return;
    }
    if (c == 13 || c == 14){
        a[0] = -4e18;
        a[n + 1] = 4e18;
        int pos;
        for (int i = 2; i < n; i++) if (a[1] + m >= a[i] && a[i] + m >= a[n]){
            pos = i;
            break;
        }
        int ll = lower_bound(a + 1,a + n + 1,a[pos + 1] - m) - a,lr = lower_bound(a + 1,a + n + 1,a[pos + 2] - m) - a - 1,rl = upper_bound(a + 1,a + n + 1,a[pos - 2] + m) - a,rr = upper_bound(a + 1,a + n + 1,a[pos - 1] + m) - a - 1,ans = 0;
        for (int i = 1; i < ll; i++){
            int p = max(rl,(int)(upper_bound(a + 1,a + n + 1,a[i] + m) - a));
            ans += max(0ll,rr - p + 1);
        }
        for (int i = n; i > rr; i--){
            int p = min(lr,(int)(lower_bound(a + 1,a + n + 1,a[i] - m) - a - 1));
            ans += max(0ll,p - ll + 1);
        }
        cout << ans << '\n';
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        dp[i] = 0;
        cnt[i] = pre[i] = 1;
        pre[i - 1] = 0;
        for (int j = i + 1,k = i; j <= n; j++){
            while (a[k] + m < a[j]) k++;
            int pos = upper_bound(dp + k,dp + j,dp[k]) - dp;
            dp[j] = dp[k] + 1;
            cnt[j] = min(3ll,pre[pos - 1] - pre[k - 1]);
            pre[j] = pre[j - 1] + cnt[j];
            ans += cnt[j] == 2;
        }
    }
    cout << ans << '\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (cin >> c >> t; t--; solve());
    return 0;
}//我怀疑此题比 replace 简单，但我没有证据