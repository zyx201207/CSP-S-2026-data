#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 1e5 + 5;
int n, m;
int a[N];
bool vis[M];
int ans[M];
queue<int> q1, q2;
void pback(int k) {
    while (!q1.empty()) {
        q1.pop();
    }
    for (int i = k + 1; i <= n; i++) {
        q1.push(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        vis[i] = false;
    }
    while (!q2.empty()) {
        q2.pop();
    }
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q1.push(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int k = i; k <= n; k++) {
            int aa = q1.front();
            q1.pop();
            if (vis[aa] == true) {
                while (!q2.empty()) {
                    int aaa = q2.front();
                    vis[aaa] = false;
                    q2.pop();
                }
            }
            q2.push(aa);
            vis[aa] = true;
        }
        for (int j = 1; j <= m; j++) {
            if (vis[j] == true) {
                ans[j]++;
            }
        }
        pback(i);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
//zen me yi si shen mi da mo ni.
//na you du gui tian tian shu
//pai dui yi chu shi sha a
