#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int a[N];
vector<int> f;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    int c , t;
    cin >> c >> t;
    while (t--)
    {
        int n;
        long long d;
        cin >> n >> d;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 2; i <= n; i++)
        {
            if (a[i] - a[i - 1] > d)
            {
                f.push_back(i - 1);
            }
        }
        if (n < 2 * d)
        {
            cout << 0 << "\n";
            continue;
        }
        for (int i = 1; i < n - 2 * d; i++)
        {
            bool r = true;
            for (int j = 0; j < f.size(); j++)
            {
                if (f[j] < i)
                {
                    continue;
                }
                if (f[j] >= i + 2 * d - 1)
                {
                    break;
                }
                r = false;
                break;
            }
            if (r)
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
