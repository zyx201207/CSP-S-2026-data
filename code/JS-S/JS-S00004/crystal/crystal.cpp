#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define endl "\n"
using namespace std;

vector<int> a, presum;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    a.push_back(0);
    presum.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        a.push_back(ai);
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++)
    {
        presum.push_back(presum[i - 1] + a[i]);
    }
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i - 1, ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid) - (presum[i - 1] - presum[mid - 1]) <= m)
            {
                ans = i - mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cnt = max(cnt, ans + 1);
    }
    cout << cnt << endl;
    return 0;
}
