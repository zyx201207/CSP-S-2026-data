#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
#include <queue>
#include <map>
#include <unordered_map>

namespace std {
    class Read {
        public:
        template<typename T>
        inline Read operator >> (T & x) {
            T sum = 0; signed opt = 1;
            char ch = getchar();
            while(!isdigit(ch)) opt = (ch == '-') ? -1 : 1, ch = getchar();
            while( isdigit(ch)) sum = (sum << 1) + (sum << 3) + (ch ^ 48), ch = getchar();
            x = sum * opt; return (*this);
        }
    };
}
#define int long long
#define all(a) a.begin(), a.end()
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)
#define endl "\n"

using namespace std; Read fin;

using PII = pair<int, int>;

const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, d; fin >> n >> d;

    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i ++ )
        fin >> arr[i];

    int cnt = 0;

    for (int i = 1; i <= n; i ++ ) {
        int j = upper_bound(1 + all(arr), arr[i] + d) - arr.begin() - 1;

        if (i >= j - 1) continue;

        int l = max(arr[j], arr[j - 2] + d + 1);
        int r = arr[j - 1] + d;

        int pos1 = lower_bound(1 + all(arr), l) - arr.begin();
        int pos2 = upper_bound(1 + all(arr), r) - arr.begin() - 1;

        pos1 = max(pos1, j);

        if (pos2 < pos1) continue;
        // cout << i << " " << j << " " << pos1 << " " << pos2 << endl;
        cnt += pos2 - pos1 + 1;
    }

    cout << cnt << endl;
}

signed main() {
    IO("migrate");

    int c, T; fin >> c >> T;

    while(T -- ) {
        solve();
    }
}