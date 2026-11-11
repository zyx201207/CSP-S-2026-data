#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10;
int n;
long long a[N], ans = -1e9, m;

int check(long long x)
{
    long long res = 0;
    for(int i = 1; i <= n; i++) if(a[i] <= x) res += x - a[i];
    if(res <= m)
    {
        int tans = 0;
        for(int i = 1; i <= n; i++) if(a[i] <= x) tans++;
        return tans;
    }
    return -1;
}
bool check2()
{
    for(int i = 1; i <= n; i++) if(a[i] != i) return 0;
    return 1;
}
bool check3()
{
    for(int i = 2; i < n; i++) if(a[i] - a[i - 1] != a[i + 1] - a[i]) return 0;
    return 1;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if(check2())
    {
        for(int k = n; k >= 1; k--)
        {
            if((k - 1) * k <= 2 * m)
            {
                cout << k << endl;
                return 0;
            }
        }
    }
    if((a[n] - a[1]) * n <= 2e8)
    {
        for(int i = a[1]; i <= a[n]; i++)
        {
            long long res = 0, tans = 0;
            int id = 0;
            for(int j = 1; j <= n; j++)
            {
                if(a[j] > i) {id = j - 1; break;}
            }
            for(int j = id; j >= 1; j--)
            {
                if(res + i - a[j] <= m) tans++, res += i - a[j];
                else break;
            }
            //cout << i << ' ' << res << endl;
            ans = max(ans, tans);
        }
        cout << ans << endl;
        return 0;
    }
    long long l = a[1], r = a[n];
    while(l <= r)
    {
        long long mid = (l + r) / 2;
        int k = check(mid);
        //cout << mid << ' ' << k << endl;
        if(k != -1) l = mid + 1, ans = k;
       else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
