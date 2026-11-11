#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[500010], b[300010], cnt[300010];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) if (b[a[i]] == 0) b[a[i]] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (b[a[j]] != 0) j = b[a[j]];
            cnt[a[j]]++;
        }
    }
    for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
    return 0;
}

