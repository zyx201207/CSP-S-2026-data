#include <bits/stdc++.h>

using namespace std;

int a[500005];
int num[300005];
int fz[300005];
int main () {
    int n , m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    memset(num , 0 , sizeof(num));
    queue<int> q;
    for (int i = 1; i <= n; i ++) {
        memset(fz , 0 , sizeof(fz));
        for (int j = i; j <= n; j ++) {
            if (fz[a[j]] == 1) {
                int u = q.front();
                while (u != a[j] && !q.empty()) {
                    fz[u] --;
                    q.pop();
                    u = q.front();
                }
            } else {
                q.push(a[j]);
                fz[a[j]] ++;
            }
        }

        for (int j = 1; j <= m; j ++) {
            num[j] += fz[j];
        }
    }

    for (int i = 1; i <= m; i ++) {
        cout << num[i] << ' ';
    }
    return 0;
}
