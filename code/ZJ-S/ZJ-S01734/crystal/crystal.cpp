#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5E5+5;
int n, m, a[N], sub[N], sf[N], sff[N];

bool check(int x, int p) {
    return sff[p-x+1] - sff[p] - (x-1)*sf[p] <= m;
}

int getl(int x) {
    int l=1, r=x, mid, ans=1;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(check(mid, x)) ans = mid, l=mid+1;
        else r = mid-1;
    }
    return ans;
}

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    sort(a+1, a+n+1);
    for(int i=1;i<n;i++) {
        sub[i] = a[i+1] - a[i];
    }
    for(int i=n-1;i>=1;i--) {
        sf[i] = sf[i+1] + sub[i];
    }
    for(int i=n-1;i>=1;i--) {
        sff[i] = sff[i+1] + sf[i];
    }
    int ans = 0;
    for(int i=n;i>=1;i--) {
        ans = max(ans, getl(i));    
    }
    cout << ans << '\n';

    return 0;
}