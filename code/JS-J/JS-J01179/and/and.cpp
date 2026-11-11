#include <iostream>
#include <algorithm>
using namespace std;

#define INF (1<<30)+1

int n, m, a[2000010];

int ans = 0;
void dfs(int step, int sum, int cnt)
{
    if (step > n)
    {
        if (cnt == m)
            ans = max(ans, sum);
        return ;
    }
    if (ans > sum) return ;
    if (m - cnt > n - step + 1) return ;
    dfs(step + 1, sum, cnt);
    if (cnt < m) dfs(step + 1, (sum==INF ? a[step] : sum&a[step]), cnt + 1);
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> a[1];
    int maxn = a[1], sum = a[1];
    bool isA = ((1<<__lg(a[1]+1)) == a[1]+1);
    for (int i = 2; i <= n; i++)
        cin >> a[i], maxn = max(a[i], maxn), sum &= a[i], isA = isA && ((1<<__lg(a[i]+1)) == a[i]+1);
    if (isA) {
        sort(a + 1, a + n + 1);
        cout << a[n-m+1] << '\n';
    }
    else if (m == 1) cout << maxn << '\n';
    else if (m == n) cout << sum << '\n';
    else if (m == 2) {
        ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                ans = max(ans, a[i] & a[j]);
        cout << ans << '\n';
    } else {
        dfs(1, INF, 0);
        cout << ans << '\n';
    }
    return 0;
}
