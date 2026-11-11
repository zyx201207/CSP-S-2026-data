#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i = (a);i <= (b);i++)
#define rep(i,a,b) for(ll i = (a);i < (b);i++)
#define pb push_back

ll n,m;
ll mx = 0;
ll ans = 0;
ll ar[100005];

void dfs(ll x,ll st){
   // cout << x << ' ' << st << ' ' << mx << '\n';
    if(x == n && st != m) return;
    if(st == m){
        ans = max(ans,mx);
        return;
    }
    dfs(x+1,st);
    ll temp = mx;
    mx &= ar[x+1];
    dfs(x+1,st+1);
    mx = temp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    repe(i,1,n) cin >> ar[i];
    if(m==n){
        ll ans = ar[1];
        repe(i,2,n) ans &= ar[i];
        cout << ans << '\n';
        return 0;
    }
    if(m == 1){
        ll ans = ar[1];
        repe(i,2,n) ans = max(ans,ar[i]);
        cout << ans;
        return 0;
    }
    repe(i,1,n){
        mx = ar[i];
        dfs(i,1);
    }
    cout << ans;
    return 0;
}