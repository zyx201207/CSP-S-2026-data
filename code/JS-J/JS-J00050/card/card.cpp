#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    srand(time(0));
    for (int i = 0; i < m; i++)
        cout << rand() % n + 1 << ' ';
    return 0;
}
