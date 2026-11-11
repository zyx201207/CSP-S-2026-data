#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n+5];
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int sum=a[n];
    while(m)
    {
        sum=(sum&a[n-m]);
        m--;
    }
    cout<<sum;
    return 0;
}
