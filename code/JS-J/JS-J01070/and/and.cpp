#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
bool cmp(int a, int b){
    return a > b;
}
int a[N];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    if(m == 1) cout << a[1];
    else if(m == 2){
        int ans = a[1] & a[2];
        cout << ans;
    }
    else{
        ll ans = a[1] & a[2];
        for(int i = 3; i <= m; i++) ans = ans & a[3];
        cout << ans;
    }
    return 0;
}
