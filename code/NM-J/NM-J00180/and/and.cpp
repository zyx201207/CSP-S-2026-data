#include <bits/stdc++.h>
using namespace std;
int a[200010],maxx=-0x3f3f3f3f3f;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==m)
    {
        for(int i=1;i<=n-1;i++)
        {
            maxx=a[i]&a[i+1];
        }
        cout<<maxx;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            maxx=max(maxx,a[i]&a[j]);
        }
    }
    cout<<maxx;
}
