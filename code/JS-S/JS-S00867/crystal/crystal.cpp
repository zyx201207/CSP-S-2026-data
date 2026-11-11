#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i = (l); i <= (r); ++i)
#define per(i,l,r) for(int i = (l); i >= (r); --i)
#define pii pair<int,int>
#define ll long long
using namespace std;
const int N = 5e5+10, inf = 0x3f3f3f3f, mod1 = 1e9+7, mod2 = 998244353;
const ll mod3 = 114514191981007219ll;
ll pre[N+10], a[N+10], n, m;
void solve(){
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    sort(a+1,a+n+1);
    rep(i,1,n) pre[i] = pre[i-1] + a[i];
    int l = 1, ans = 0;
    rep(i,1,n){
        while(l <= i && a[i] * (i-l) - pre[i-1] + pre[l-1] > m) ++l;
        ans = max(ans, i - l + 1);
    }
    cout << ans << "\n";
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while(T--) solve();
    return 0;
}