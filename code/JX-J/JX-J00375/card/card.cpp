#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
int a[5 * N];
int b[5 * N];
int c[5 * N];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cout << a[1] + 2 << a[1] * 2 << a[i] * 2 - 1;
    return 0;
}
