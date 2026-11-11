#include<bits/stdc++.h>
using namespace std;
typedef long long i64;

const int N=500010;
int n;
i64 m, a[N], s[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    s[0]=0;
    for(int i=1;i<=n;i++) {
        s[i]=s[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        int l=0, r=i+1;
        function<bool(int)> check=[&](int x) {
            if(a[i]*(i-x+1)-s[i]+s[x-1]<=m) {
                return true;
            }
            else {
                return false;
            }
        };
        while(l+1<r) {
            int mid=(l+r)>>1;
            if(check(mid)) {
                r=mid;
            }
            else {
                l=mid;
            }
        }
        ans=max(ans, i-r+1);
    }
    cout << ans << '\n';
    return 0;
}
