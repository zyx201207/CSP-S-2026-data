#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 2e5 + 10;
const ll X = pow(2, 31) - 1;
ll n, m;
ll a[N];
void dfs(ll dep, ll sum, ll &ans, ll last){
    if (dep == m){
        ans = max(ans, sum);
        return;
    }
    for (ll i = last + 1; i <= n; ++ i){
        dfs(dep + 1, (sum & a[i]), ans, i);
    }
}
bool cmp(ll x, ll y){
    return x > y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    if (n <= 20){
        ll ans = 0;
        dfs(0, X, ans, 0);
        cout << ans << endl;
        return 0;
    }
    if(m == 1){
        ll maxx = -1;
        for (ll i = 1; i <= n; ++ i){
            maxx = max(a[i], maxx);
        }
        cout << maxx << endl;
        return 0;
    }
    if (m == n){
        ll ans = a[1];
        for (ll i = 2; i <= n; ++ i){
            ans = (ans & a[i]);
        }
        cout << ans << endl;
        return 0;
    }
    bool f1 = 1;
    for (ll i = 1; i <= n; ++ i){
        ll t = log2(a[i]);
        if (pow(2, t) != a[i]){
            f1 = false;
            break;
        }        
    }
    if (f1){
        sort(a + 1, a + n + 1,cmp);
        cout << a[m];
        return 0;
    }
    bool f2 = 1;
    ll t = log2(n);
    if (pow(2, t) != n) f2 = false;
    for (int i = 1; i <= n; ++ i){
        if (a[i] != i - 1){
            f2 = false;
            break;
        }
    }
    if (f2){
        sort(a + 1, a + n + 1, cmp);
        cout << a[m];       
    }
    bool f3 = 1;
    for (int i = 1; i <= n; ++ i){
        if (a[i] >= t){
            f3 = 0;
            break;
        }
    }
    if (f3){
        int c1, c2, c3;
        c1 = c2 = c3 = 0;
        for (int i = 1; i <= n; ++ i){
            if (a[i] == 1) c1 ++;
            else if (a[i] == 2) c2 ++;
            else c3 ++;
        }
        if (m <= c3) cout <<3;
        if (m <= c2 + c3) cout << 2;
        else cout << 0;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    cout << a[m];
    return 0;
}
//