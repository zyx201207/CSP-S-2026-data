#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long c,t;
long long n,d;
long long x[2000005],f[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
            cin >> x[i];
        sort(x + 1,x + n + 1);
        f[x[1]] = 1;
        for (int i = 2;i <= n;i++)
        {
            for (int j = i - 1;j >= 1;j--)
            {
                if (x[i] - x[j] <= d)
                    f[x[i]] += f[x[j]];
                else
                    break;
            }
        }
        long long num = 0;
        for (int i = 2;i <= n;i++)
            for (int j = i - 1;j >= 1;j--)
                if (f[x[i]] / f[x[j]] == 2)
                    num++;
        cout << num << endl;
    }
    return 0;
}
