#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long sum,maxn;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n-m;i++)
    {
        sum=a[i+1];
        for (int j=i+1;j<=i+m;j++)
        {
            sum=(sum&a[j]);
        }
        maxn=max(maxn,sum);
    }
    cout<<maxn;
    return 0;
}
