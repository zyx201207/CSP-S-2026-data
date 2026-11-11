#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
int n;
ll m;
ll a[N];

int main(){ 
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1;
    ll cur = 0;
    int ans = 0;
    for(int r = 1; r <= n; r++){
        while(l < r && cur > m){
            cur -= a[r] - a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
        if(r < n) cur += 1ll * (r - l + 1) * (a[r + 1] - a[r]);
    }
    cout << ans << endl;
    return 0;
}