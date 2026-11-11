#include <bits/stdc++.h>
using namespace std;
int n,maxx;
long long m,a[500005],q[500005];
bool check(int x,int now) {
    if (a[now] * (now - x + 1) - (q[now] - q[x-1]) <= m) return 1;
    return 0;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a + 1,a + 1 + n);
    for (int i = 1; i <= n; i++) q[i] = q[i-1] + a[i];
    for (int i = 1; i <= n; i++) {
        int l = 0,r = i,lastmid = 0;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (lastmid == mid) break;
            lastmid = mid;
            if (check(mid,i)) r = mid;
            else l = mid + 1;
        }
        maxx = max(maxx,i - r + 1);
    }
    cout << maxx;
    return 0;
}
