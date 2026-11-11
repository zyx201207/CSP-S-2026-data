#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500003];
int n,m;
int add=0;
bool cmp(int a,int b)
{
    return a<b;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
     for(int i=2;i<=n;i++)
    {
        add+=(a[i]-a[i-1])*(i-1);
        if (add>m)
        {
            cout<<i-1;
            break;
            return 0;
        }
    }
    return 0;
}
