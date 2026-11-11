#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int n, m, a[500007], has[300007], cnt[300007];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> a[i];

    for (int i = 0; i < n; i ++) {
        stack<int> pl;
        for (int j = 1; j <= m; j ++) has[j] = -1;
        for (int j = i; j < n; j ++) {
            if (has[a[j]] > -1) {
                while (! pl.empty() && pl.top() != a[j]) {
                    has[pl.top()] = -1;
                    pl.pop();
                }
            } else {
                has[a[j]] = j;
                pl.push(a[j]);
            }
        }
        for (int j = 1; j <= m; j ++) cnt[j] += (has[j] > -1);
    }

    for (int i = 1; i <= m; i ++) cout << cnt[i] << ' ';

    fclose(stdin);
    fclose(stdout);
    return 0;
}
