#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    a[n+1]=sum;
    ll sum1=0;
    for(ll i=1;i<=n+1;i++)
    {
        a[i]=abs(sum-a[i]);
        sum1+=a[i];
    }
    sort(a+1,a+n+1);
    ll maxx=-1;
    int pos;
    for(ll i=1;i<=n+1;i++)
    {
        if(a[i]==0)
        {
            pos=i;
            break;
        }
    }
    int cnt=0;
    for(ll i=1;i<=n;i++)
    {
        if(m>=a[i])
        {
            m-=a[i];
            cnt++;
        }
        else
            break;
    }
    cout<<cnt;
    return 0;
}
