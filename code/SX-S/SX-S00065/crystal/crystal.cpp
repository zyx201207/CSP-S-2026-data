#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,a[N],ans=-1e9,m,gc;
bool f=1;

bool cmp(ll x,ll y)
{
    return x>y;
}

bool c(ll x)
{
    if((ll)m-(((ll)x*(ll)a[1])+(ll)gc*((ll)x*((ll)x-1)/2))>=0)
        return 1;
    return 0;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    gc=a[2]-a[1];
    for(int i=3; i<=n; i++)
    {
        if(a[i]-a[i-1]!=gc)
            f=0;
    }
    if(f==1)
    {
        if(gc!=0)
        {
            ll sum1=0,l=0,r=1000000005;
            while(l<=r)
            {
                ll mid=(l+r)/2;
                if(c(mid))
                {
                    l=mid+1;
                    sum1=mid;
                }
                else
                    r=mid-1;
            }
            cout<<sum1+1;
            return 0;
        }
        else
        {
            cout<<n;
            return 0;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; i++)
    {
        ll mid=a[i],rs=m,sum=1;
        for(int j=i+1; j<=n; j++)
        {
            if(rs>=mid-a[j])
            {
                rs-=mid-a[j];
                sum++;
            }
            else
            {
                break;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
