#include<bits/stdc++.h>
#define in inline 
#define int long long 

using namespace std;
const int M = 5e5 + 5;
int n, k, ans, a[M], sum[M], cnt;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int j = 1;
    for(int i = 1; i <= n; i++) {
        while(j <= i && a[i] * (i - j) - (sum[i - 1] - sum[j - 1]) > k) j++;
        ans = max(ans, i - j + 1);
    } cout << ans << '\n';
    return 0;
}