#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
    ll x=0;char c=getchar();
    while (!isdigit(c))c=getchar();
    while (isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x;
}

ll a[500005],sm[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    ll ps=1;
    for (ll i=1;i<=n;i++)sm[i]=sm[i-1]+a[i];
    ll ans=0;
    for (ll i=1;i<=n;i++){
        while (ps<=i&&a[i]*(i-ps+1)-(sm[i]-sm[ps-1])>m)ps++;
        ans=max(ans,i-ps+1);
    }
    cout<< ans;
    return 0;
}
