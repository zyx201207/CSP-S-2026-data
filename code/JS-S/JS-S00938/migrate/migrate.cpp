#include <iostream>
#define ll long long
using namespace std;
const int N = 2000005;
int c, t, n;
ll d, x[N];
bool check()
{
    for (int i = 3; i <= n; i++)
        if (x[i] - x[i - 1] != x[2] - x[1])
            return false;
    return true;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        if (check())
        {
            ll gc = x[2] - x[1];
            ll k = 2 * (d / gc) - 1;
            if (k > n)
                cout << 0;
            else if (k >= 2)
                cout << n - k;
            else
                cout << 0;
            cout << '\n';
        }
    }
    return 0;
}
