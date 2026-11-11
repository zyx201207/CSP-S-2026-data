#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 24;
int n, k;
int a[N], s[N];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for(int i = 1, j = 1; i <= n && j <= n; i++)
    {
        while(j < n)
        {
            if(a[j + 1] * (j - i + 2) - (s[j + 1] - s[i - 1]) <= k) j++;
            else break;
        }
        ans = max(ans, j - i + 1);
        //cout << i << " " << j << "\n";
        //cout << ans << "\n";
    }
    cout << ans;
    return 0;
}
