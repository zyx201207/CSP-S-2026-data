#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
ll a[N],m,pre[N];
int n;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int flag1=1,flag2=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i) flag1=0;
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3) flag2=0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    ll ans=LLONG_MIN;
    if(flag1)
    {
        ll cnt=0,i=1;
        for(i=1;i<=n&&cnt<=m;i++) cnt+=i;
        cout<<i+1;
    }
    else if(flag2)
    {
        ll cnt=0,i=1,cha=a[2]-a[1];
        for(;cnt<=m;i++) cnt+=i*cha;
        cout<<i+1;
    }
    else
    {
        for(int i=n;i>1;i--)
        {
            int l=1,r=i-1;
            ll ansi=i;
            while(l<=r)
            {
                int mid=(l+r)/2;
                ll po=pre[i]-pre[mid-1];
                if(a[i]*(i-mid+1)-po<=m)
                {
                    ansi=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            ans=max(ans,i-ansi+1);
        }
        cout<<ans;
    }
    return 0;
}
