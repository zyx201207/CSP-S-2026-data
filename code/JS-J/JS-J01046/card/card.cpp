#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int n, m;
int a[MAXN];
int ans[MAXN];
int mp[MAXN];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    if (m == 2) {
        int cnt1=0, cnt2=0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                cnt1++;
            } else {
                cnt2++;
            }
        }
        if (a[n]==1) {
            cout << n << ' ' << cnt2 << endl;
        } else {
            cout << cnt1 << ' ' << n << endl;
        }
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]=max(mp[a[i]], i);
    }
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j <= n) {
            j = mp[a[j]];
            ans[a[j]]++;
            j++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
/*
2 1 2 2 2 2 2 2 1 2 1 2 1 2 1

*/
