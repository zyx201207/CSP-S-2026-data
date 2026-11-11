#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second

const ll N=5e5+5;
const ll inf=1e9;
const ll mod=1e9+7;

ll _;
ll n,m;
ll a[N];
ll pre[N];
ll ans;

void solve()
{ 
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(ll i=1;i<=n;i++)
    {
        ll L=1,R=i,ret=i;
        while(L<=R)
        {
            ll mid=L+R>>1;
            // cerr<<i<<" "<<a[i]<<" "<<mid<<" "<<pre[i-1]<<" "<<pre[mid-1]<<"\n";
            if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m)
            {
                R=mid-1;
                ret=mid;
            }
            else L=mid+1;
        }
        ans=max(ans,i-ret+1);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    // cin>>_;
    _=1;
    while(_--)
    {
        solve();
    }

    return 0;
}
/*
g++ crystal.cpp -o crystal -std=c++14
/usr/bin/time -v ./1
*/
