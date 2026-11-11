#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
pair <int, int> lr[N];
vector <int> edge[N];
int dis[N];
int n, k;
int X, Y;
int S, T;
void dfs(int x, int fa) {
    if (dis[x] > dis[S]) {
        S = x;
    }
    for (auto i : edge[x]) {
        if (i == fa)continue;
        if (x == X && i == Y)continue;
        if (x == Y && i == X)continue;
        dis[i] = dis[x] + 1;
        dfs(i, x);
    }
    return;
}

bool in[2000005];
vector <int> L;

bool find(int x, int fa) {
    if (x == T) {
        L.push_back(x);
        in[x] = 1;
        return 1;
    }
    for (auto i : edge[x]) {
        if (i == fa)continue;
        if (x == X && i == Y)continue;
        if (x == Y && i == X)continue;
        if (find(i, x)) {
            L.push_back(x);
            in[x] = 1;
            return 1;
        }
    }
    return 0;
}

int MID;
bool all = 0;
int sum = 0;
int del(int x, int fa) {
    int mx = 0;
    for (auto i : edge[x]) {
        if (i == fa)continue;
        if (x == X && i == Y)continue;
        if (x == Y && i == X)continue;
        if (in[i])continue;
        mx = max(mx, del(i, x) + 1);
        if (all)return 0;
    }
    if (mx >= MID) {
        sum++;
        if (sum > k) {
            all = 1;return 0;
        }
    }
    return mx;

}

bool check(int mid) {
    MID = mid;
    dis[X] = 0;
    S = X;
    dfs(X, 0);
    T = S;
    dfs(S, 0);

    sum = all = 0;

    L.clear();
    find(S, 0);
    int len = (int)L.size();
    // for (auto i : L)cout << i << "*";
    // cout << endl;
    for (int i = mid; i <= len - mid - 1; i++) {
        if (del(L[i], 0) < MID) {
            sum++;
            if (sum > k)all = 1;
        }
//        cout << L[i] << ":" << sum << "(\n";
        if (all) {
            for (auto j : L) {
                in[j] = 0;
            }
            return 0;
        }
    }
    for (auto i : L) {
        in[i] = 0;
    }
    if (!sum)sum++;

    int TS = sum;

    MID = mid;
    dis[Y] = 0;
    S = Y;
    dfs(Y, 0);
    T = S;
    dfs(S, 0);

    L.clear();
    find(S, 0);
    len = (int)L.size();
    for (int i = mid; i <= len - mid - 1; i++) {
        if (del(L[i], 0) < MID) {
            sum++;
            if (sum > k)all = 1;
        }
//        cout << L[i] << ":" << sum << ")\n";
        if (all) {
            for (auto j : L) {
                in[j] = 0;
            }
            return 0;
        }
    }
    for (auto i : L) {
        in[i] = 0;
    }
    if (TS == sum) {
        sum++;
        if (sum > k)return 0;
    }
    return 1;
}

signed main() {
   freopen("hub.in", "r", stdin);
   freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            edge[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
            lr[i] = {a, b};
        }
        int ans = n - 1;
        for (int i = 1; i < n; i++) {
            X = lr[i].first, Y = lr[i].second;
            if (ans - 1 < 0 || !check(ans - 1))continue;
            int l = 0, r = ans - 1, tmp = ans - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (check(mid)) {
                    tmp = mid;
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }
            ans = tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}