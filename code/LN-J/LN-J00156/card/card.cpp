#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;
int n, m;
int a[500005];
unordered_map<int, bool> vis;
deque<int> q;
unordered_map<int, int> sum;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        vis.clear();
        for (int j = i; j <= n; ++j) {
            if (!vis.count(a[j]) || !vis[a[j]]) {
                q.push_back(a[j]);
                vis[a[j]] = true;
             } else {
                while (!q.empty()) {
                    if (q.back() == a[j])
                        break;
                    vis[q.back()] = false;
                    q.pop_back();
                }
            }
        }
        while (!q.empty()) {
            ++sum[q.front()];
            q.pop_front();
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d ", sum[i]);
    }
    printf("\n");
    return 0;
}
