#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i ++ )
#define DF(i, a, b) for (int i = (a); i >= (b); i -- )
inline void chkmin(int& a, int b) { if (a > b) a = b; }
inline void chkmax(int& a, int b) { if (a < b) a = b; }

const int N = 500010;

int n, m, a[N], lst[N];
int dp[N];
int sum[N];

signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    F(i, 1, n) cin >> a[i], lst[a[i]] = i;
    F(i, 1, n)
    {
        int nxt = lst[a[i]] + 1;
        dp[i] ++ ;
        if (nxt <= n) dp[nxt] += dp[i];
    }
    F(i, 1, n) sum[a[i]] += dp[i];
    F(i, 1, m) cout << sum[i] << " ";
    cout << "\n";
    return 0; 
}