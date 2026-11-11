#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+4;
int n;
ll m, a[N], sum[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1, a+1+n);
    for (int i=1;i<=n;++i) sum[i] = sum[i-1]+a[i];
    int ans = 0;
    for (int i=1;i<=n;++i){
        int l = 0, r = i, mid;
        while (l<r){
            int mid = l+r>>1;
            if (a[i]*(i-mid)-sum[i]+sum[mid]<=m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i-l);
    }
    cout << ans << '\n';
    return 0;
}