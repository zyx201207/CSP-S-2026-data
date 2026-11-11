#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 2e5 + 5, ST = (1ll << 31) - 1;
int n, k, ans, a[N];
deque<int> choose;
void dfs(int x, int t, deque<int> choose)
{
    if (x > n + 1 || t > k)
        return;
    if (t == k)
    {
        int cnt = choose.back();
        choose.pop_back();
        while (!choose.empty())
            cnt &= choose.back(), choose.pop_back();
        ans = max(ans, cnt);
        return;
    }
    choose.push_back(a[x]);
    dfs(x + 1, t + 1, choose);
    choose.pop_back();
    dfs(x + 1, t, choose); 
}
signed main()
{
     freopen("and.in", "r", stdin);
     freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    int mx = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, 0, choose);
    cout << ans;
    return 0;
}
