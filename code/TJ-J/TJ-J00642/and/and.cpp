#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200000];
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        long long x;
        cin >> x;
        a[i]=x;
    }
    sort(a+1,a+1+n);
    for(int i=n-1;i<=n-m;i--)
    {
        a[i]=a[i] and a[i+1];
    }
    cout << a[n-m+1];
    return 0;
}
