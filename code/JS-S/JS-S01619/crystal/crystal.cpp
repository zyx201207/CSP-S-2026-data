#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
const int N = 5e5 + 10;
ll a[N], sum[N];
bool check(int x){
    for (int i = 1; i <= n - x; ++ i){
        // left node
        ll need = a[i + x - 1] * (x - 1) - (sum[i + x - 2] - sum[i - 1]);
        if (need <= m){
            return 1;
        } 
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++ i){
        sum[i] = a[i] + sum[i - 1];
    }
    ll l = 1, r = n * 2;
    while (l + 1 < r){
        ll mid = l + (r - l) / 2;
        if (check(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}