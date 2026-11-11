#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[200010];
int dp[200010];
int ans;

bool cmp(int x, int y) {return x >= y;}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);

    dp[1] = a[1];
    for (int i = 2; i <= n; ++i) for (int j = min(i, m); j >= 2; --j) dp[j] = max(dp[j], dp[j - 1] & a[j]);

    cout << dp[m];

    fclose(stdin);
    fclose(stdout);
    return 0;
}
