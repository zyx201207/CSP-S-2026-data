#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500100],d[500100],s[500100],ss[500100];
int n,m;
int getx(int a,int b)
{
    return ss[a]-ss[b+1]-(b+1-a)*(s[b+1]);
}
bool check(int x)
{
    for(int i=2;i+x-1<=n;i++)
    {
        if(getx(i,i+x-1)<=m)
        {
            return 1;
        }
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        d[i]=a[i]-a[i-1];
    }
    if(d[1]<0)d[1]=0;
    for(int i=n;i>=1;i--)
    {
        s[i]=s[i+1]+d[i];
        ss[i]=ss[i+1]+s[i];
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout << ss[i] << " ";
    // }
    //cout << endl;
    int l=1,r=1e6,mid=(l+r)/2;
    while(l<=r)
    {
        if(check(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
        mid=(l+r)/2;
        //cout << mid << " ";
    }
    //cout << endl;
    //cout << getx(1,3);
    cout << mid+1;
    return 0;
}