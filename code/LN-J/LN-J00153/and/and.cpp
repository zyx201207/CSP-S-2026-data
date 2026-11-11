#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    if (m>=n)
    {
        for (int i = 2;i<=n;i++)
        {
            a[i] = a[i]&a[i-1];
        }
        cout << a[n];
    }
    return 0;
}
