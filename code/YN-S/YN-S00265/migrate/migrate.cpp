#include <bits/stdc++.h>

using namespace std;
using num = long long;

num c, t;

void tsk1() {
    while (t--) {
        num n, d;
        cin >> n >> d;
        vector<num> a(n + 1);
        for (num i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        num p = a[2] - a[1];
//        cerr << n << ' ' << d << ' ' << p << '\n';
        num times = d / p;
        if (times < 2) {
            cout << "0\n";
            continue;
        }
        cout << max(n - 2 * times + 1, 0ll) << '\n';
    }
}

void tsk2() {
    while (t--) {
        num n, d, mx = -0x3f3f3f3f3f3f3f3f;
        cin >> n >> d;
        vector<num> a(n + 1);
        for (num i = 1; i <= n; ++i) {
            cin >> a[i];
//            mx = max(mx, a[i]);
        }
        num ans = 0;
        vector<num> g(n + 1);
        queue<num> q;
        for (num s = 1; s <= n; ++s) {
            vector<num> border = {s}, border_size = {1};
            g[s] = 1;
            q.push(s);
            num right = s;
            for (; right < n; ) {
                num nxt = -1;
                for (num l = right + 1, r = n; l <= r; ) {
                    num mid = l + (r - l) / 2;
                    if (a[mid] <= a[right] + d) {
                        nxt = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                if (nxt == -1) {
                    break;
                }
                border.push_back(nxt);
                border_size.push_back(nxt - right);
                right = nxt;
            }
            for (num i = 1; i < border.size(); ++i) {
                num sum = 0, one = -1, two = -1;
                for (num last = border[i - 1], j = 0; j < border_size[i - 1] && j < 3; --last, ++j) {
                    sum += g[last];
                    num x = 0x3f3f3f3f3f3f3f3f;
                    for (num l = border[i - 1] + 1, r = border[i]; l <= r; ) {
                        num mid = l + (r - l) / 2;
                        if (a[mid] > a[last] + d) {
                            x = mid;
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }
                    if (sum == 1) {
                        ;
                    } else if (sum == 2) {
                        one = x;
                    } else if (sum == 3) {
                        two = x;
                    } else {
                        break;
                    }
                }
                if (two == 0x3f3f3f3f3f3f3f3f) {
                    ans += 0;
                } else if (two != -1) {
                    ans += border[i] - two + 1 - (one == -1 ? 0 : border[i] - one + 1);
                } else {
                    ans += border_size[i] - (one == -1 ? 0 : border[i] - one + 1);
                }
                for (num last = border[i], j = 0; j < border_size[i] && j < 3; --last, ++j) {
                    q.push(last);
                    if (last >= one) {
                        g[last] = 1;
                    } else if (last >= two) {
                        g[last] = 2;
                    } else {
                        g[last] = 3;
                    }
                }
            }
            while (!q.empty()) {
                g[q.front()] = 0;
                q.pop();
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> t;
    if (c == 11 || c == 12) {
        tsk1();
        return 0;
    }
    while (t--) {
        num n, d;
        cin >> n >> d;
        vector<num> a(n + 1);
        for (num i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        num ans = 0;
        for (num s = 1; s <= n; ++s) {
            vector<num> f(n + 1), g(n + 1);
            g[s] = 1;
            for (num i = s + 1; i <= n; ++i) {
                num left = -1;
                for (num l = 1, r = i - 1; l <= r; ) {
                    num mid = l + (r - l) / 2;
                    if (a[i] - a[mid] <= d) {
                        left = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                f[i] = f[left] + 1;
                for (num j = left; j < i; ++j) {
                    if (f[j] != f[left]) {
                        break;
                    }
                    g[i] += g[j];
                    g[i] = min(g[i], 3ll);
                    if (g[i] == 3) {
                        break;
                    }
                }
                if (g[i] == 2) {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}