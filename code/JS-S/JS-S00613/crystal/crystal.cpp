#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500010],A[500010];
bool chk(ll l,ll cs)
{
    ll sum = A[cs] - A[l-1];
    ll num = cs-l+1;
    ll t = a[cs]*num - sum;
    if(t<=m)return true;
    return false;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i =1; i<=n; i++)
    {

        A[i] = A[i-1]+a[i];
    }
    ll mx = 1;
    for(ll cs=1; cs<=n; cs++)
    {
        ll t =a[cs];
        ll l=1,r=cs;
        while(l+1<r)
        {
            ll mid = (l+r)/2;
            //end in l+1=r
            if(chk(mid,cs))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        ll tans=-1;
        if(chk(l,cs))tans = cs-l+1;
        else if(chk(r,cs))tans = cs-r+1;
        mx = max(mx,tans);
    }
    cout<<mx<<endl;
//1234567890123456789012345678901234567

    return 0;
}

