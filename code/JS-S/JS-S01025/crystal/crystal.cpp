#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 500005;
typedef long long LL;

LL arr[N], sum[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    int n; LL m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];

    // [mid, i] merge
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i, ans = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (sum[i] - sum[mid - 1] + m >= arr[i] * (i - mid + 1))
                ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        res = max(res, i - ans + 1);
    }

    cout << res;

    return 0;
}
