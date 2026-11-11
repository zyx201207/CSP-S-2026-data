// BLuemoon_
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 2e6 + 5;
const LL kP = 1e9 + 7;

LL cT, T = 1, n, k, a[kMaxN], ans, s[kMaxN], p[kMaxN], L[kMaxN], R[kMaxN];

bool Chk(int l, int r, bool F = 0) {
    if (s[l] < r && s[l] > l + 1) {
        int i = s[l] - 1;
        F = (s[l] == i + 1 && p[r] == i && s[i] == r && s[i + 1] == r && p[i] == l && p[i + 1] == l);
    }
    return F;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
    for (cin >> cT >> T; T; T--, ans = 0) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n <= 3) {
            cout << "0\n";
            continue;
        }
        for (int i = 2; i <= n; i++) {
            a[i] -= a[1];
        }
        a[1] = 0;
        for (int i = 1; i <= n; i++) {
            int L = i, R = n;
            for (int mid = L + R + 1 >> 1; L < R; mid = L + R + 1 >> 1) {
                a[mid] - a[i] <= k ? L = mid : R = mid - 1;
            }
            s[i] = L;
            L = 1, R = i;
            for (int mid = L + R >> 1; L < R; mid = L + R >> 1) {
                a[i] - a[mid] <= k ? R = mid : L = mid + 1;
            }
            p[i] = L;
        }
        if (cT == 11 || cT == 12) {
            k /= a[2];
            if (k <= 1) {
                cout << "0\n";
            } else {
                cout << max(0ll, n - k - k + 1) << '\n';
            }
        } else {
            for (int i = 1; i <= n; i++) {
                L[i] = R[i] = 1;
                for (int j = i; p[j] != j; j = p[j], L[i]++) {
                }
                for (int j = i; s[j] != j; j = s[j], R[i]++) {
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = i + 3; j <= n; j++) {
                    LL cnt = 0;
                    vector<int> pos;
                    for (int l = i; l < j; l = s[l], cnt++) {
                        if (s[l] == l) {
                            cnt = -1;
                            break;
                        }
                        pos.push_back(l);
                    }
                    if (cnt == -1) {
                        continue;
                    }
                    pos.push_back(j);
                    if (pos.size() == 2) {
                        continue;
                    }
                    int F = -1, sz = pos.size();
                    for (int l = 1; l < sz - 1; l++) {
                        if (pos[l] == pos[l - 1] + 1) {
                            continue;
                        }
                        if (l == sz - 2 ? (s[pos[l] - 1] >= pos[l + 1]) : (s[pos[l] - 1] == pos[l + 1])) {
                            if (pos[l] == pos[l - 1] + 2) {
                                if (F == -1) {
                                    F = l;
                                } else {
                                    F = -1;
                                    break;
                                }
                            } else {
                                if (s[pos[l] - 2] < pos[l + 1]) {
                                    if (F == -1) {
                                        F = l;
                                    } else {
                                        F = -1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (F == -1) {
                        continue;
                    }
                    // if (p[pos[F] - 1] == pos[F - 1]) {
                    //     for (int l = 0; l < sz; l++) {
                    //         cout << pos[l] << ' ';
                    //     }
                    //     cout << '\n';
                    // }
                    ans += p[pos[F] - 1] == pos[F - 1];
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
// g++ migrate.cpp -o migrate -O2 -static -Wall && time ./migrate