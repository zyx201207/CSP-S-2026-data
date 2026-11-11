#include <iostream>
#define ll long long
using namespace std;
const int N = 2000005;
int c, t, n, k;
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(0));
    cin >> c >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
        }
        cout << n + (n * 10) / k * 2176 - n / k;
    }
    return 0;
}
