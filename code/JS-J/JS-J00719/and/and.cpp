#include <bits/stdc++.h>
using namespace std;

const int N = 20010;
int n, m;
long long a[N], dp[N];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dp[j] = max(dp[j], (dp[j - 1] & a[j]));
        }
    }
    cout << dp[m] << endl;
    return 0;
}
