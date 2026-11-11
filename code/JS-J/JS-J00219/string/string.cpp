#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, a[N], ans;
char c[N];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    while (l < r)
    {
        if (c[l] == c[r])
        {
            if (a[l] < a[r])
            {
                a[r] -= a[l];
                l++;
            }
            else
            {
                a[l] -= a[r];
                r--;
            }
        }
        else
        {
            if (a[l] < a[r])
            {
                ans += a[l];
                a[r] -= a[l];
                l++;
            }
            else
            {
                ans += a[r];
                a[l] -= a[r];
                r--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
