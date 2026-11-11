#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500001], sum[500001];
int find_(int pos){
    int l = 1, r = pos - 1, ans = 0;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[pos] * (pos - mid) - (sum[pos - 1] - sum[mid - 1]) <= m){
            ans = pos - mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans + 1;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    int maxx = 0;
    for (int i = 1; i <= n; i++)
        maxx = max(maxx, find_(i));
    cout << maxx;
    return 0;
}
