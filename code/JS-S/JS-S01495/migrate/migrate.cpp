#include <iostream>
#include <cstring>
using namespace std;
int t, n, c;
long long d, a[2000001];
void dp()
{
    for (int i = 1;i <= t;i++)
    {
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        long long s = a[2] - a[1];
        d /= s;
        if (d == 1 || d == 0 || n <= 3)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << max(n - d * 2 + 1, 0ll) << endl;
        }
        memset(a, 0, sizeof(a));
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    dp();
    return 0;
}
