#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i ++ )
#define DF(i, a, b) for (int i = (a); i >= (b); i -- )
inline void chkmin(int& a, int b) { if (a > b) a = b; }
inline void chkmax(int& a, int b) { if (a < b) a = b; }

const int N = 500010;

int n, m, a[N], sum[N];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    F(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    F(i, 1, n) sum[i] = sum[i - 1] + a[i];
    int res = 0;
    F(i, 1, n)
    {
        int l = 1, r = i, best = i;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) best = mid, r = mid - 1;
            else l = mid + 1;
        }
        chkmax(res, i - best + 1);
    }
    cout << res << "\n";
    return 0;
}