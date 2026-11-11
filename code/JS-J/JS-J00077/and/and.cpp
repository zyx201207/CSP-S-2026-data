#include <bits/stdc++.h>
using namespace std;

int n, m, ii;
long long a[200010];

int main()
{
    freopen("1", "r", stdin);
    //freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    int sum = a[n-1];
    for(int i = n-2;i >= n-m;i--)
    {
        sum &= a[i];
    }
    cout << ((sum == 0) ? a[n-1]-1 : sum) << endl;
    return 0;
}