#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace langfengya
{
    void Main();
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    langfengya::Main();
    return 0;
}

namespace langfengya
{
    int n, m;
    const int N = 5e5 + 10;
    int a[N];
    int que[N];
    int sum = 0;
    void read()
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
    }
    void solve()
    {
        int ans = 0, count = 0;
        int head = 1, tail = 0;
        for (int i = 1; i <= n; i++)
        {
            while (head <= tail && count * a[i] - sum > m)
            {
                sum -= a[que[head]];
                count--;
                head++;
            }
            ans = max(ans, count + 1);
            que[++tail] = i;
            count++;
            sum += a[i];
        }
        cout << ans << endl;
    }
    void Main()
    {
        read();
        solve();
    }
}