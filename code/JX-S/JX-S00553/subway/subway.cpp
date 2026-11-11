#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;
ll n,m;
ll a[N],b[N],pre[N];
ll ans = 1;

bool check(ll x)
{
    ll sum = 0;
    for(int i = 1 ; i <= x ; i++)
    {
        sum += abs(a[x]-a[i]);
    }
    return sum <= m;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >>a[i];
    sort(a+1,a+n+1);
    for(int i = 1 ; i <= n ; i++) b[i] = abs(a[i]-a[i-1]),pre[i] = pre[i-1]+a[i];


    ll l = 1,r = n;
    while(l <= r)
    {
        ll mid = (l+r)/2;
        if(check(mid)){l = mid+1;}
        else r = mid - 1;
    }
    cout << l-1 << "\n";
    return 0;
}
