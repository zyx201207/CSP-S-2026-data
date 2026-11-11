#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 500010;
const int MAXM = 300010;

int a[MAXN], ans[MAXM], n, m;
bool b[MAXM];
int st[MAXN], t;

void solve() {
    for (int v=1; v<=n; v++) {
        for (int i=1; i<=m; i++) b[i] = false;
        st[0] = a[v];
        t = 1;
        b[a[v]] = true;
        for (int i=v+1; i<=n; i++) {
            if (!b[a[i]]) {
                st[t++] = a[i];
                b[a[i]] = true;
            } else {
                while (t>0) {
                    if (st[t-1] == a[i]) break;
                    b[st[t-1]] = false;
                    t--;
                }
            }
        }
        for (int i=1; i<=m; i++) {
            if (b[i]) ans[i] ++;
        }
    }
    for (int i=1; i<=m; i++) printf("%d ", ans[i]);
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w" , stdout);
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);

    if (m<=2 && n>5000) {
        int s1 = 0, s2 = 0;
        for (int i=1; i<=n; i++) {
            if (a[i] == 1) s1 ++;
            if (a[i] == 2) s2 ++;
        }
        if (a[n] == 1) printf("%d %d", n, s2);
        else printf("%d %d", s1, n);
    } else {
        bool f = true;
        for (int i=2; i<=n; i++) {
            if (a[i] < a[i-1]) f = false;
        }
        if (f) {
            for (int i=1; i<=n; i++) {
                ans[a[i]] = i;
            }
            for (int i=1; i<=m; i++) printf("%d ", ans[i]);
        } else {
            solve();
        }
    }
    return 0;
}
