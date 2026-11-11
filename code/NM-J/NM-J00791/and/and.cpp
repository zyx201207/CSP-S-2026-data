#include "bits/stdc++.h"
using namespace std;

int a[200010];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m, a1;
    int ma = 0;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n, greater<int>());

    cout << a[m];


    return 0;
}
