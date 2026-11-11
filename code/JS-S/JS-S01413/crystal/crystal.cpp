#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt=0,n=0,m=0;
vector<ll> a(5*1e5+500,0);

bool check(ll mid)
{
    ll sum=0,now_m=m;
    for(ll i=mid;i>=1;i--)
    {
        if(a[mid]-a[i]<=now_m) sum++,now_m-=a[mid]-a[i];
        else break;
    }
    if(sum>=cnt)
    {
        cnt=sum;
        return true;
    }
    else return false;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a.begin()+1,a.begin()+n+1);
    ll l=1,r=n;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%lld",cnt);
    return 0;
}
