#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int l,r,mid;
bool check(int x)
{
    int ans=0x3f;
    for(int i=1;i<=n-x+1;i++)
    {
        int temp=0;
        for(int j=i;j<=i+x-1;j++)
        {
            temp+=(a[i+x-1]-a[j]);
        }
        ans=min(temp,ans);
    }
    if(ans>m)return false;
    return true;
}
bool cmp(int x,int y)
{
    return x<y;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    l=1,r=n;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid)==false)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<l-1;
    return 0;
}
