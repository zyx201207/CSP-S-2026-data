#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> n >> m;
    srand(time(0));
    for (int i = 1; i <= m; ++i)
    {


        int m = rand() % 10000;
        cout << m << "\n";
    }
    return 0;
}
