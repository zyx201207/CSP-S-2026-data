#include <bits/stdc++.h>
using namespace std;
int n,m,i;
int a[500005],b[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=1;i<=m;i++)
    {
        cout<<n-i+1<<' ';
    }
    return 0;
}
