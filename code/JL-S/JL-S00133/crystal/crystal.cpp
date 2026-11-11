#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 500005;
LL a[N], s[N], n, m;
void work()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i=1;i<=n;i++)
        s[i] = s[i - 1] + a[i];
    int ans = 1;
    for (int i=1;i<=n;i++)
    {
        int j = i;
        while (j < n && a[j] == a[j + 1])
            j ++;
        int l = 1, r = i - 1, pos = i;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid) - (s[i - 1] - s[mid - 1]) <= m)
                pos = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        ans = max(ans, j - i + 1 + i - pos);
        i = j;
    }
    cout << ans;
}
int main()
{
    freopen("crystal.in", "r", stdin);freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--)work();
    return 0;
}
