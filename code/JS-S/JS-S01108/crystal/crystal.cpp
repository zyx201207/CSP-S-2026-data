#include <bits/stdc++.h>
#define ll long long
#define MAXN 500005
#define INF 1000000007
#define MOD 998244353
using namespace std;

ll n,m;
ll a[MAXN];

bool check(ll k){
    ll s = 0;
    for(ll i = 2; i <= n; i++){
        s += min(i - 1,k - 1) * (a[i] - a[i - 1]);
        if(i > k)s -= a[i] - a[i - k];
        if(i >= k && s <= m)return 1;
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    ll l = 1,r = n;
    ll mid = ((l + r) >> 1) + 1;
    while(l < r){
        if(check(mid))l = mid;
        else r = mid - 1;
        mid = ((l + r) >> 1) + 1;
    }
    cout<<l<<"\n";
    return 0;
}
