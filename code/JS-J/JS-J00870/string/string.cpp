#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,a[N];
char b[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i]>>b[i];
    ll l1=1,l2=0,r1=n,r2=a[n]+1,ans=0;
    while(l1<r1)
    {
        ll x=a[l1]-l2;
        ll y=r2-1;
        ll z=min(x,y);
        if(b[l1]!=b[r1]) ans+=z;
        l2+=z;
        r2-=z;
        if(l2==a[l1])
        {
            l1++;
            l2=0;
        }
        if(r2==1)
        {
            r1--;
            r2=a[r1]+1;
        }
    }
    cout<<ans;
    return 0;
}
