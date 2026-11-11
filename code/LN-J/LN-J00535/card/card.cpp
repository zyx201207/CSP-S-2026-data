#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m;
int a[5 * N], ans[3 * N];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            bool flag = 0;
            int cnt = 0;
            while (!q.empty() && cnt < q.size()) {
                int t = q.front();
                q.pop();
                if (t == a[j]) flag = 1;
                q.push(t);
                cnt++;
            }
            queue<int> q1;
            if (flag) {
                bool flag1 = 0;
                while (!q.empty()) {
                    if (q.front() == a[j]) flag1 = 1;
                    if (!flag1) q1.push(q.front());
                    q.pop();
                }
                while (!q1.empty()) {
                    q.push(q1.front());
                    q1.pop();
                }
            }
            q.push(i);
        }
        while (!q.empty()) {
            ans[q.front()]++;
            q.pop();
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
