#include <bits/stdc++.h>
using namespace std;

long long dp[5055][5055], dp2[5055][5055];
long long a[5055];

void solve(){
    long long n, d;
    cin >> n >> d;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    long long ans = 0;
    for(long long i = 1;i <= n;i++){
        long long l = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
        dp[i][i] = 0;
        dp2[i][i] = 1;
        for(long long ls = 1;ls < i;ls++){
            long long mn = 1e9, mncnt = 0;
            for(long long j = l;j < i;j++){
                if(dp[ls][j] < mn){
                    mn = dp[ls][j];
                    mncnt = dp2[ls][j];
                }
                else if(dp[ls][j] == mn) mncnt += dp2[ls][j];
            }
            if(mncnt == 2) ans++;
            dp[ls][i] = mn + 1;
            dp2[ls][i] = mncnt;
        }
    }
    cout << ans << "\n";
    return ;
}

int main(){
    //16:23:35 first finish(won't TLE if N < 300)(but it maybe wrong answer)(migrate 3 WA)
    //16:39:44 after thinking for sometime, i found the mistake and now it can get 24 points
    //16:43:31 i really wish time can go faster, i'm very tired and want to go to bed
    //17:24:17 i really got nothing to do, but there's 1 hour and 6 minutes left
    //17:30:00 still one hour left o_o, i will try to get more points in this problem
    //17:40:52 maybe i should give up, i'm sooooo tired
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        solve();
    }
}
