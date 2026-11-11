#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 500005;
int n, ans;
LL m, a[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1, a+n+1);
    LL sum = 0;
    for(int i=1,j=1;i<=n;i++) {
        sum += (LL)(a[i]-a[i-1])*(i-j);
        while(sum > m) {
            sum -= a[i]-a[j];
            j++;
        }
        ans = max(ans, i-j+1);
    }
    cout << ans;
    return 0;
}