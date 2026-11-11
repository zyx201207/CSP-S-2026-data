#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int sum[N];
int n, m;
int f(int i)
{
    int l = 1, r = i;
    //if (i == 2)
    //{
    //    cout << l << " " << r << '\n';
    //}
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if ((i - mid + 1) * a[i] - sum[i] + sum[mid - 1] > m)
        {
            l = mid + 1;
        }
        else if ((i - mid + 1) * a[i] - sum[i] + sum[mid - 1] < m)
        {
            r = mid - 1;
        }
        else
        {
            //cout << i << "          " << mid << "     " << sum[mid - 1] << '\n';
            return mid;
        }
      //  if (i == 3)
      //  {
      //      cout << l << " " << r << '\n';
      //  }
    }
    //cout << i << " " << l << " " << r << '\n';
    return l;
}
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
    int tmp = a[1];
    for (int i = 1; i <= n; i++)
    {
        a[i] -= tmp;
        sum[i] = a[i] + sum[i - 1];
        //cout << a[i] << " " << sum[i] << endl;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        //cout << f(i) << '\n';
        ans = max(ans, i - f(i) + 1);
    }
    cout << ans << '\n';
    return 0;
}




