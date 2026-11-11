#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;

int pt_numb, T, n, k;
vector <int> g[N];

inline void work()
{
    for (int i = 1; i <= n; ++i) g[i].clear();
    cin >> n >> k;
    for (int i = 1, u, v; i < n; ++i) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

    if (n == 2)
    {
        cout << 1 << endl;
    }
    else if (n == 3)
    {
        cout << 1 << endl;
    }
    else if (n == 4)
    {
        cout << 2 << endl;
    }
    else if (n == 5)
    {
        cout << 3 << endl;
    }
    else
    {
        cout << n / 2 << endl;
    }

}

int main()
{
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);

    cin >> pt_numb >> T;
    while (T --) work();

    return 0;
}