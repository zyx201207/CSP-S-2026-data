#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500010];
int ans[500010];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int round = 1; round <= n; round++) {
        int desk[500010] = {0};
        int ed = 0;
        for (int i = round; i <= n; i++) {
            for (int j = 1; j <= ed; j++) {
                if (desk[j] == a[i]) {
                    ed = j;
                    break;
                }
            }
            desk[++ed] = a[i];
            //for (int i = 1; i <= ed; i++) {
            //    cout << desk[i] << ' ';
            //}
            //cout << '\n';
        }
        map<int, bool> vis;
        for (int j = 1; j <= ed; j++) {
            ans[desk[j]] += !vis[desk[j]];
            vis[desk[j]] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
// wo chang chang zhui yi guo qu
// wo gai tin liu zai na?
// wo wen wo zi ji
// wan dan le dou xue oi 3nian le
// j zu hai shi bu neng ak me
// shi fou gai kao lv afo le
// this problem 48+pts pls orz
// luogu uid 713602
// any human can read?
// 2026-10-31 10:58:27
// green -> aqua?
// not a ez problem
// i can solve it faster, but i wont to do that
// we lost
// look like just 24pts
// 2026-10-31 11:17:13
// tired, why i cant solve it, im so ****
// 2026-10-31 11:30:01
// i belive ccf's gold computer
// 2026-10-31 11:50:51
// j zu shu le s zu ke jiu bu neng shu le o
// 2026-10-31 11:59:59
