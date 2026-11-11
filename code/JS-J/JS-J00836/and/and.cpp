#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=2*1e5+5;
ll n,m;
ll a[MAXN],arr[MAXN];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1){
        cout<<0;
        return 0;
    }else if(m==n)
    {
        ll ans=a[1];
        for(ll i=2;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }else if(m==2)
    {
        ll idx=0;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                if(a[i]==a[j])
                {
                    cout<<a[i];
                    return 0;
                }
                arr[idx++]=a[i]&a[j];
            }
        }
        sort(arr,arr+idx);
        cout<<arr[idx-1];
        return 0;
    }else{
        ll idx=0,f=0;
        sort(a,a+n+1);
        ll ans=a[n];
        for(int i=n-1;i>n-m;i--)
        {
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
