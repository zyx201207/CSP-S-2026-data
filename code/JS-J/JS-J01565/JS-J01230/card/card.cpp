#include <bits/stdc++.h>
using namespace std;


const int MAXN = 5e5 + 10;
const int MAXM = 3e5 + 10;
int n;
int m;
int cnt[MAXM];
int a[MAXN];
int p[MAXM];
int pos[MAXN];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (p[a[i]] != 0) {
            pos[i] = p[a[i]];
        }
        else {
            pos[i] = i;
        }
        p[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        stack<int> stk;
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= j - pos[j] && !stk.empty(); k++) {
                stk.pop();
            }
            stk.push(a[j]);
        }
        while (!stk.empty()) {
            cnt[stk.top()]++;
            stk.pop();
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }
    cout << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
