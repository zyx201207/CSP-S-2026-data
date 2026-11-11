#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

ll n, a[N], m, sum[N], sum2[N], ans;

bool P(ll x, ll w){
    return (sum2[w] - sum2[x]) - (x - 1) * (sum[w] - sum[x]) <= m;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++){
        sum[i] = sum[i - 1] + (a[i] - a[i - 1]);
        sum2[i] = sum2[i - 1] + (i - 1) * (a[i] - a[i - 1]);
    }
    for(int i = 1; i <= n; i++){
        ll l = 1, r = n;
        while(l <= r){
            int mid = (l + r) / 2;
            if(P(mid, i)){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}
/*

1 2 3 4 5 6 7

3 2 1

5 8
-3 -1 2 2 7

5 5
1 2 4 8 9

*/
