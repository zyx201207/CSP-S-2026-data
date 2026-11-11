#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,m;
int maxn=0;
int a[200005];
bool flag=true;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        maxn=a[1];
        for(int i=2;i<=n;i++)
        {
            maxn=maxn&a[i];
        }
        cout<<maxn;
        return 0;
    }
    cout<<0;
    return 0;
}
