#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5;
int a[2 * N];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cout << a[n];
    return 0;
}
