#include <bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+5;
long long a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    bool ok2=true;
    long long d=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==2)
        {
            d=a[i]-a[i-1];
        }
        else if(i>=3)
        {
            if(a[i]-a[i-1]!=d)
            {
                ok2=false;
            }
        }
    }
    if(ok2)
    {
        long long l=1,r=n;
        long long pos=0;
        while(l<=r)
        {
            long long mid=(l+r)>>1;
            if((mid*(mid-1)/2)<=m/d)
            {
                pos=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        cout<<pos<<"\n";
        return 0;
    }
    sort(a+1,a+n+1);
    long long ans=0;
    int pos=1;
    for(int i=1;i<=n;i++)
    {
        ans=0;
        for(int j=i+1;j<=n;j++)
        {
            long long q=m-(j-i)*(a[j]-a[j-1]);
            if(ans>q)
            {
                pos=max(pos,j-i);
                break;
            }
            else
            {
                ans+=(j-i)*(a[j]-a[j-1]);
            }
        }
    }
    cout<<pos<<"\n";
    return 0;
}
