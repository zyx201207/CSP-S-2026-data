#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 10;
ll m;
ll n,ans;
ll a[maxn],s[maxn];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a + 1,a + 1 + n,greater<ll>());
    for(ll i=n;i>=1;i--) s[i] = s[i + 1] + a[i];
    for(ll i=1;i<=n;i++)
    {
        if(((n - i) * a[i] - s[i + 1]) <= m) {printf("%lld\n",n - i + 1);return 0;}
        //cout << s[i] << ' ';
    }
    return 0;
}
/*
70 pts
O(n log n)
AG.ZOE NB
*/