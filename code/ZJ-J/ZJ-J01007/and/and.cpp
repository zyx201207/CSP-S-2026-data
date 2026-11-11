#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int m, n, len;
int a[maxn];
vector<int> bit[maxn];
void calc(vector<int>& bi, int pos) {
    int x = a[pos];
    while (x) {
        bi.push_back(x % 2);
        x /= 2;
    }
    len = max(len, (int)bi.size());
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        calc(bit[i], i);
    }
    for (int i = 1; i <= n; i++) {
        if ((int)bit[i].size() != len) {
            int x = len - bit[i].size();
            while (x) {
                x--;
                bit[i].push_back(0);
            }
        }
        reverse(bit[i].begin(), bit[i].end());
        // for (int j = 0; j < len; j++) cout << bit[i][j];
        // cout << '\n';
    }
    long long ans = 0;
    vector<pair<int, int>> need;
    for (int i = 1; i <= n; i++) need.push_back({bit[i][0], i});
    for (int i = 0; i < len; i++) {
        int k = need.size();
        int cnt = 0;
        vector<pair<int, int>> new_need;
        for (int j = 0; j < k; j++) {
            if (need[j].first == 1) {
                cnt++;
                new_need.push_back({bit[need[j].second][(i == len - 1 ? 0 : i + 1)], need[j].second});
            }
        }
        // cout << cnt << '\n';
        if (cnt < m) {
            for (int j = 0; j < k; j++) if (need[j].first == 0) new_need.push_back({bit[need[j].second][(i == len - 1 ? 0 : i + 1)], need[j].second});
            need = move(new_need);
        }
        else {
            ans = ans | (1 << (len - i - 1));
            need = move(new_need);
        }
    }
    cout << ans << '\n';
    return 0;
}