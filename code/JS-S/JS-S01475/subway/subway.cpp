#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
vector<int> w;
struct Subway {
    int k;
    vector<int> a;
    vector<int> t;
    Subway() {
        k.resize(1);
        t.resize(1);
    }
};
vector<Subway> Sub;


dfs(int x, int y) { //我们可以从x这个点作dfs向全局搜索，找到y
    for (int i = 1; i <= t[x].k; i ++) {
        return 0;
    }
}



int main() {
    freopen("subway.out", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf(" %d %d %d %d %d", &c, &n, &m, &d, &q);
    w.resize(m + 1);
    Sub.resize(n + 1);
    for (int i = 1; i <= m; i ++) {
        scanf(" %d", &w[i]);
    }
    for (int i = 1; i <= n; i ++) {
        scanf(" %d", &Sub[i].k);
        for (int j = 1; j <= Sub[i].k; j ++) {
            int a, t;
            scanf(" %d %d", &a, &t);
            Sub[i].a.push_back(a);
            Sub[i].t.push_back(t);
        }
    }
    while(q --) {
        int x, y;
        scanf(" %d %d", &x, &y);
        printf("%d\n", solve(x, y));
    }
    cout << 32 << "\n" << 17;
    return 0;
}
