#include <bits/stdc++.h>
using namespace std;
long long n,m,a[111111],b[111111],c;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=2;i<=n;i++)
    {
        b[i-1]==a[i]-a[i-1];
    }
    sort(b,b+n);
    c=1;
    for (int i=1;i<=n;i++)
    {
        if(b[i]<=m)
        {
            m-=b[i];
            ++c;
        }
    }
    cout<<c;
    return 0;
}
