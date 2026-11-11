#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e6 + 5;

int c, t;
int a[MAXN];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> t;
    while(t--)
    {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int l = a[2] - a[1];
        int s = d / l;
        cout << s * l << endl;
    }
    return 0;
}
