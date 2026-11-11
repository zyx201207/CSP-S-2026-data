#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 5e5 + 5;
LL n, m, a[N];
LL minn = 2e9, maxn = -2e9, sub;
int ans;
bool flag = true;

void chk(int x) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
        q.push(abs(a[i] - x));
    int sum = 0, cnt = 0;
    while (sum <= m) {
        if (sum + q.top() > m)
            break;
        sum += q.top();
        q.pop();
        cnt++;
    }
    ans = max(ans, cnt);
}

void solve() {
    for (int i = minn; i <= maxn; i++)
        chk(i);
}

void solve_sp() {
    int maxn, res;
    if (n % 2 == 1) {
        maxn = 1, res = m;
        for (int i = 1; i <= (n - 1) / 2; i++) {
            if (2 * sub * i <= res) {
                res -= 2 * sub * i;
                maxn += 2;
            }
            else {
                if (sub * i <= res)
                    maxn++;
                break;
            }
        }
    }
    else {
        maxn = 0, res = m;
        for (int i = 1; i <= n / 2; i++) {
            if (i == 1) {
                if (sub > m) {
                    maxn = 1;
                    break;
                }
                else {
                    maxn = 2;
                    res -= sub;
                }
            }
            else {
                if (2 * sub * i - sub <= res) {
                    res -= 2 * sub * i - sub;
                    maxn += 2;
                }
                else {
                    if (sub * i - sub <= res)
                        maxn++;
                    break;
                }
            }
        }
    }
    ans = maxn;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        minn = min(minn, a[i]);
        maxn = max(maxn, a[i]);
    }
    if (n >= 2) {
        sub = a[2] - a[1];
        for (int i = 3; i <= n; i++)
            if (a[i] - a[i - 1] != sub)
                flag = false;
    }

    if (flag == true)
        solve_sp();
    else
        solve();

    printf("%d\n", ans);
    return 0;
}