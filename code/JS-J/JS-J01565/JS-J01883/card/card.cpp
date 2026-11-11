#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5+10;
int b[N];
int a[N];
bool vis[N];
int ret[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    memset(vis, 0, sizeof(vis));
    int n, m;
    cin >> n >> m;
    if (n <= 5) {
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            int id = 0;
            for (int j = i; j <= n; j++) {
                int x = b[j];
                if (vis[x] == 0) {
                    a[id] = x;
                    id++;
                    vis[x] = 1;
                } else {
                    int idx = -1;
                    for (int i = 0; i < id; i++) {
                        if (a[i] == x) {
                            idx = i;
                        }
                    }
                    for (int i = idx; i < id; i++) {
                        a[i] = 0;
                        id--;
                    }
                    a[id] = x;
                    id++;
                }
                if (j == n) {
                    for (int k = 0; k <= id; k++) {
                        ret[a[k]]++;
                    }
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            cout << ret[i] << " ";
        }
    }

    return 0;
}
