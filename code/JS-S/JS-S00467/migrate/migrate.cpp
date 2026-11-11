#include<bits/stdc++.h>
#define int long long
using namespace std;

int c, t;
int n, d, a[5001], cnt[5001], dp[5001], ans, dpcnt[5001];

bool check(int s, int t)
{
    for (int i = s; i <= t; i++) dp[i] = 0,  dpcnt[i] = 0;
    for (int i = 0; i <= 5000; i++) cnt[i] = 0;
    cnt[0]++;
    int l = s;
    set<int>tt;
    tt.insert(0);
    dpcnt[s] = 1;
    for (int i = s+1; i <= t; i++)
    {
        int now = a[i];
        while (l < i && now-a[l] > d)
        {
            cnt[dp[l]] -= dpcnt[l];
            if(cnt[dp[l]] <= 0) tt.erase(dp[l]);
            l++;
        }
        dp[i] = *tt.begin()+1;
        dpcnt[i] = cnt[*tt.begin()];
        tt.insert(dp[i]);
        cnt[dp[i]]++;
    }
    if (dpcnt[t] == 2) return 1;
    else return 0;
}

void solve()
{
    cin >> n >> d;
    ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int l = 1; l <= n; l++)
    {
        for (int r = l+1; r <= n; r++)
        {
            ans += check(l, r);
        }
    }
    cout << ans << endl;
}

main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--) solve();
    return 0;
}
