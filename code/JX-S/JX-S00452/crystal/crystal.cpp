#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n; ll m;
ll a[N], sum[N];
int ans;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = n, j = n; i >= 1; i--){
        while(j >= 1 && (i - j + 1) * a[i] - (sum[i] - sum[j - 1]) <= m){
            ans = max(ans, i - j + 1);
            j--;
        }

    }
    cout << ans;
    return 0;
}

