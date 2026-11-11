#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005],sum;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum=a[n];
    for(int i=1;i<=m-1;i++)
    {
        sum=(sum&a[n-i]);
    }
    cout<<sum;
    return 0;
}
