#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
ll b[N];
ll ans;
ll sum;
ll diff[N];
ll dife[N];
ll x[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    memset(x,1,sizeof(x));
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1])
            x[i]++;
    }
    if(m>=abs(a[n])*n||a[1]==a[n])
    {
        cout<<n<<endl;
    return 0;
    }
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    else if(n==2)
    {
        if(a[1]+m>=a[2])
        {
            cout<<2;
            return 0;
        }
        else
            cout<<1;
        return 0;
    }
    bool f=0;
    ll cnt=0;
    for(ll i=1;i<=n;i++)
    {
        if(abs(a[i]-a[i+1])==abs(a[i+1]-a[i+2]))
        {
             cnt=abs(a[i+1]-a[i]);
             f=1;
             break;
        }
    }
   if(f==1)
    {
        for(ll i=1;i<=n;i++)
        {
        if(m>=0)
        {
            m-=cnt*i;
            ans++;
        }
        else if(m<0)
        {
            cout<<ans<<endl;
            break;
        }
        }
    }
    else
    {
        for(ll i=1;i<=n;i++)
        {
            diff[i]=abs(a[n]-a[i]);
        }
        for(ll i=1;i<=n;i++)
        {
            diff[0]=diff[1];
            dife[i]=diff[i]-diff[i-1];
        }
        for(ll i=1;i<=n;i++)
        {

                m-=abs(dife[i]);
            if(m>=0)
            {
                ans++;
            }
            else
            {
                cout<<ans<<endl;
                break;
            }
        }
    }

    return 0;
}
