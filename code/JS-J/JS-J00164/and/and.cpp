#include<bits/stdc++.h>
using namespace std;
#define inf 0x37373737
const int N=2e5+5;
int a[N];
int n,m,s,x;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    s=a[1];
    x=a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        s=(s&a[i]);
        x=max(x,a[i]);
    }
    if(m==1)
    {
        cout<<x<<'\n';
        return 0;
    }
    if(m==n)
    {
        cout<<s<<'\n';
        return 0;
    }
    if(m==2)
    {
        s=-inf;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                s=max(s,(a[i]&a[j]));
            }
        }
        cout<<s<<'\n';
        return 0;
    }
    return 0;
}