#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,ans;
long long m,a[500003];

inline bool check(int x) {
    for (int i = x;i <= n;i++) {
        bool f = 0;
        if ((ll)x * (a[i] - a[i - 1]) - (a[i] - a[i - x - 1]) <= m) f = 1;
        if (f) return 1;
    } return 0;
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 2;i <= n;i++) a[i] += a[i - 1];
    int l = 0,r = n;
    while (l <= r) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            ans = max(ans,mid);
            l = mid + 1;
        } else r = mid - 1;
    } cout << ans;
    return 0;
}
