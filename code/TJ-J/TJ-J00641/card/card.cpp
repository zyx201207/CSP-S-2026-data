#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MAXN = 5e5 + 100;

int n, m, a[MAXN], ans[MAXN];
stack<int> stk;
bool instk[MAXN];

void solve(int s)
{
    while (!stk.empty()) {
        stk.pop();
    }
    memset(instk, 0, sizeof(instk[0]) * (m + 1));
    for (int i = s; i <= n; i++) {
        if (instk[a[i]]) {
            while (stk.top() != a[i]) {
                instk[stk.top()] = false;
                stk.pop();
            }
        } else {
            stk.push(a[i]);
            instk[a[i]] = true;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (instk[i]) {
            ans[i]++;
        }
    }
}

void solveA()
{
    for (int i = 1; i <= n; i++) {
        ans[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void solve2()
{
    ans[a[n]] = n;
    int p = 1;
    while (a[p] != a[n]) {
        p++;
    }
    ans[3 - a[n]] = p - 1;
    cout << ans[1] << " " << ans[2] << endl;
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    bool isA = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < a[i - 1]) {
            isA = false;
        }
    }
    if (isA) {
        solveA();
        return 0;
    }
    if (m == 1) {
        cout << n << endl;
        return 0;
    }
    if (m == 2) {
        solve2();
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
