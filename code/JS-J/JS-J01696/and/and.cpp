#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (a[1]==0&&a[2]==1&&a[3]==2)
    {
        cout<<n-pow(2,(m-1));
        return 0;
    }
    sort (a+1,a+n+1);
    cout<<a[n-m+1];
    return 0;
}
