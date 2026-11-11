#include <bits/stdc++.h>
using namespace std;
freopen("subway.in", "r", stdin);
freopen("subway.out", "w", stdout);
int main()
{
    int n,m,t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(t <= n && t >= 0)
            {
                n += t;
            }
            else
            {
                t = m * t;
                j++;
            }
        }
    }
    cout << t;
    return 0;
}
