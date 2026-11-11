#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;

    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    if (m == n) {
        int ans = a[1];
        for (int i = 1;i <= n;i++) {
            ans = ans&a[i];
        }
        cout << ans << endl;
        return 0;
    }

    cout << 0 << endl;
    return 0;
}
