#include <bits/stdc++.h>

using namespace std;

#define int long long
#define up(i, a, b) for(int i = a;i <= b; i++)
#define down(i, a, b) for(int i = a;i >= b; i--)
#define clr(x) memset(x, 0, sizeof x)

const int N = 5e5 + 101;
const int M = 3e5 + 101;

unordered_map <int, int> lstv, lst;
int stk[N], top, tong[N], a[N], n, m;
bool ins[M], clst[N];

signed main () {
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    up (i, 1, n) {
        cin >> a[i];
    }
    down (i, n, 1) {
        if (lstv.count(a[i])) {
            lst[i] = lstv[a[i]];
        }
        lstv[a[i]] = i;
    }
    up (index, 1, n) {
        top = 0;
        clr(ins);
        up (i, index, n) {
            while (lst.count(i)) {
                i = lst[i];
            }
            stk[++top] = a[i];
        }
        while (top) {
            int u = stk[top--];
            tong[u] ++;
        } 
    }
    up (i, 1, m) {
        cout << tong[i] << ' ';
    }

    return 0;
    // CSP AK!!!
}
