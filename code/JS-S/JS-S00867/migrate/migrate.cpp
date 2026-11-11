#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i = (l); i <= (r); ++i)
#define per(i,l,r) for(int i = (l); i >= (r); --i)
#define pii pair<int,int>
#define ll long long
using namespace std;
const int N = 2e6+10, inf = 0x3f3f3f3f, mod1 = 1e9+7, mod2 = 998244353;
const ll mod3 = 114514191981007219ll;
ll pre[N], suf[N], to[N];
vector<int> re[N];
ll a[N], n, d;
bool avl(int i){
    if(a[i+2] - a[i+1] <= d && a[i+1] - a[i] <= d && a[i] - a[i-1] <= d && max(a[i+1]-a[i-1], a[i+2]-a[i]) <= d) return 1;
    return 0;
}
bool check(int x, int y, int i1, int i2){
    if(min(max(a[i1]-a[x],a[y]-a[i1]), max(a[i2]-a[x],a[y]-a[i2])) <= d) return 0;
    return 1;
}
void solve(){
    cin >> n >> d;
    rep(i,1,n) cin >> a[i];
    a[0] = a[1], a[n+1] = a[n];
    rep(i,1,n+3) pre[i] = suf[i] = 0;
    rep(i,1,n) re[i].clear();
    int last = 0;
    rep(i,1,n){
        to[i] = lower_bound(a+1,a+n+1,a[i]+d) - a;
        re[to[i]].push_back(i);
        for(int j : re[i]) if(j > last) pre[i] += pre[j]; ++pre[i];
        if(avl(i)) last = i;
        if(a[i+1] - a[i] > d) last = i;
        //cout << pre[i] << " " << last << "\n";
    } //cout << "\n";
    rep(i,1,n) re[i].clear();
    last = n+1;
    per(i,n,1){
        to[i] = upper_bound(a+1,a+n+1,a[i]-d) - a - 1;
        //cout << i << " " << to[i] << '\n';
        if(to[i] != -1) re[to[i]].push_back(i);
        for(int j : re[i]) if(j < last && j != i) suf[i] += suf[j]; ++suf[i];
        if(avl(i-1)) last = i;
        if(a[i] - a[i-1] > d) last = i;
        //cout << suf[i] << " " << last << "\n";
    }
    ll ans = 0;
    rep(i,1,n) {
        int from = lower_bound(a+1,a+n+1,a[i+1]-d) - a, t = upper_bound(a+1,a+n+1,a[i]+d) - a - 1;
        ans += check(from, t, i-1, i+2) * avl(i) * pre[from] * suf[t];
        //cout << i << " " << from << " " << t << "\n";
        //cout << pre[from] << " " << suf[t] << "\n";
        //cout << i << " " << avl(i) << "\n";
    }
    cout << ans << "\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, c;
    cin >> c >> T;
    while(T--) solve();
    return 0;
}
/*
1 8 4
1 2 5 6 9 10 13 14
*/