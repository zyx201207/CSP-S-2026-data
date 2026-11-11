#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }

    vector<int> stk, pos(m + 1), cnt(m + 1);
    stk.reserve(n);

    for (int i = 0; i < n; i++) {
        stk.clear();
        fill(pos.begin(), pos.end(), -1);

        for (int j = i, p = 0; j < n; j++, p++) {
            if (pos[a[j]] != -1) {
                while (stk.size() && p - 1 != pos[a[j]]) {
                    pos[stk.back()] = -1;
                    stk.pop_back();
                    p--;
                }
                p--;
            } else {
                stk.push_back(a[j]);
                pos[a[j]] = p;
            }
        }

        for (int i : stk) {
            cnt[i]++;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}
