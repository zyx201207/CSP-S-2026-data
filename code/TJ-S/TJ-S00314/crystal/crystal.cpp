#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],diff[500005],diff2[500005],cnt;
bool check(long long x)
{
    for(int i=n;i>=x;i--)
    {
        long long xx=i;
        long long temp1=diff[xx]-diff[xx-x],temp2=diff2[xx]-diff[xx-x]*x-diff2[xx-x];
        if((x+(i-xx))*temp1-temp2<=m)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        diff[i]=a[i]-a[1];
    }
    for(int i=2;i<=n;i++)
    {
        diff2[i]=diff2[i-1]+diff[i];
    }
    long long l=1,r=n;
    while(l<r)
    {
        long long mid=(l+r+1)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
5 5
-1000000 -1 2 2 6
*/
