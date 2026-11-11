#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;
int n, m, a[N];
int ans = 0;
bool valid[N]; // can be chosen?

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    memset(valid, true, sizeof valid);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=30;i>=0;i--) {
        int cnt = 0;
        for(int j=1;j<=n;j++) {
            if((a[j] & (1<<i)) && valid[j])
                cnt++;
        }
        if(cnt >= m) {
            ans |= (1<<i);
            for(int j=1;j<=n;j++) {
                if(!(a[j] & (1<<i)))
                    valid[j] = false;
            }
        }
    }
    cout << ans;
    return 0;
}