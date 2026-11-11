#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long m ,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = 1, ans = 1;
    long long sum = 0;
    while (r <= n)
    {
        if ((a[r + 1] - a[r]) * (r - l + 1) <= m - sum)
        {
            sum += (a[r + 1] - a[r]) * (r - l + 1);
            r++;
        }
        else
        {
            while (l < r && (a[r + 1] - a[r]) * (r - l + 1) > m - sum)
            {
                sum -= a[r] - a[l];
                l++;
            }
            sum += (a[r + 1] - a[r]) * (r - l + 1);
            r++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}
