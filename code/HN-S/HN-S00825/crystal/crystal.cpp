#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int n, ans;
ll m, a[N], b[N];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
    for(int i = 1, j = 0; i <= n; i++){
        if(j < i && 1ll * (i - j) * a[i] - (b[i] - b[j]) > m) j++;
        ans = max(ans, i - j);
    }
    cout << ans;
    return 0;
}