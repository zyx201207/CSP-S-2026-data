#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5005;
int c, t;
int n, d;
int a[maxn], g[maxn][maxn];
struct node{
    int pos, dis;
};
bool bfs(int s, int e) {
    queue<node> q;
    node st;
    st.pos = s;
    st.dis = 0;
    q.push(st);
    int mindis = INT_MAX, cnt = 0;
    while (!q.empty()) {
        node fa = q.front();
        q.pop();
        if (fa.pos == e) {
            if (fa.dis == mindis) cnt++;
            if (fa.dis < mindis){
                cnt = 1;
                mindis = fa.dis;
            }
            continue;
        }
        node son;
        for (int i = fa.pos + 1; i <= e; i++) {
            if (g[fa.pos][i] == 1) {
                son.pos = i;
                son.dis = fa.dis + 1;
                q.push(son);
            }
        }
    }
    //cout << "from " << s << " to " << e << " : " << cnt << " shortest paths, mindis = " << mindis << "\n";
    if (cnt == 2) return true;
    else return false;
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                g[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if ((a[j] - a[i]) <= d) g[i][j] = 1;
                else break;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                //cout << "dis beteween " << i << " and " << j << " is " << a[j]-a[i] << " so " << d << " g[i][j] = " << g[i][j]<<"      ";
                if (bfs(i, j)) ans++;
            }
            //cout << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}
