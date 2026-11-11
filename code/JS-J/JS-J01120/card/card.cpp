#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500010], opt[500010];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        vector < int > cun;
        for (int j = i; j <= n; j ++) {
                bool flag = false;
                int idx = 0;
            for (int l = 0; l < cun.size(); l ++) {
                if (flag) cun[l] = -1;
                if (cun[l] == a[j]) {
                    flag = true;
                    cun[l] = -1;
                }
            }
            cun.emplace_back(a[j]);
        }
        for (auto x : cun) opt[x] ++;
        //cout << endl;
    }
    for (int i = 1; i <= m; i ++) cout << opt[i] << " ";
    return 0;
}
