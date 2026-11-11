#include <fstream>
#include <algorithm>

using namespace std;
using LL = long long;

const LL kMaxN = 2e6 + 5;

ifstream cin("migrate.in");
ofstream cout("migrate.out");

LL a[kMaxN], f[kMaxN], g[kMaxN], c, t, n, d, head, tail;
pair<LL, LL> q[kMaxN];

void clear() {
  head = 1, tail = 0;
}

LL size() {
  return tail - head + 1;
}

void emplace_back(LL x, LL y) {
  q[++tail] = {x, y};
}

auto front() {
  return q[head];
}

auto back() {
  return q[tail];
}

void pop_front() {
  head++;
}

void pop_back() {
  tail--;
}

int main() {
  for (cin >> c >> t; t; t--) {
    cin >> n >> d;
    for (LL i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (11 <= c && c <= 12) {
      LL p = upper_bound(a + 1, a + n + 1, a[1] + d) - a - 1;
      d = p - 1;
      if (d <= 1) {
        cout << "0\n";
      } else {
        cout << max(0LL, n - 2 * d + 1) << '\n';
      }
      continue;
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
      f[i] = 0, g[i] = 1;
      clear();
      emplace_back(i, 1);
      LL del = 0;
      for (LL j = i + 1; j <= n; j++) {
        for (; size() && a[front().first] < a[j] - d; pop_front()) {
          del += g[front().first];
        }
        if (!size()) {
          break;
        }
        f[j] = f[front().first] + 1;
        LL tar = head;
        for (LL l = head, r = tail; l <= r; ) {
          LL m = (l + r) / 2;
          if (f[q[head].first] == f[q[m].first]) {
            tar = m;
            l = m + 1;
          } else {
            r = m - 1;
          }
        }
        g[j] = q[tar].second - del;
        ans += g[j] == 2;
        for (; size() && f[j] < f[back().first]; pop_back()) { }
        emplace_back(j, (size() ? back().second : 0) + g[j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}