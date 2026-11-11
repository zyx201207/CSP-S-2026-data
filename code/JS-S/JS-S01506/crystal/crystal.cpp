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

signed main() {
    IO("crystal");

    int n, m;
    fin >> n >> m;

    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i ++ )
        fin >> arr[i];
    
    vector<int> pre(n + 1);

    sort(1 + all(arr));
    
    if ([&]() -> bool {
        for (int i = 2; i < n; i ++ )
            if (arr[i] - arr[i - 1] != arr[i + 1] - arr[i])
                return false;
        return true;
    }()) {
        for (int i = 1; i <= n; i ++ )
            pre[i] = pre[i - 1] + arr[i];

        int res = 0;

        int l = 0, r = n;

        while(l <= r) {
            int mid = l + r >> 1;

            #define len mid

            bool flag = false;

            int L = 1;
            int R = L + len - 1;
            int aver = (pre[R] - pre[L - 1]) / len;
            
            int pos = lower_bound(1 + all(arr), aver) - arr.begin();

            int sum = pre[R] - pre[pos - 1] - aver * (R - pos + 1)
                    + aver * (pos - L) - (pre[pos - 1] - pre[L - 1]);

            // cout << l << " " << r << " " << mid << " " << aver << " " << L << " " << R << " " << sum << endl;
            // cout << pre[R] - pre[pos - 1] - aver * (R - pos + 1) << " " << aver * (pos - L) - (pre[pos - 1] - pre[L - 1]) << endl;

            // cout << endl;

            if (sum <= m) { flag = true; res = max(len, res), l = mid + 1; continue; }


            aver = (pre[R] - pre[L - 1] + len - 1) / len;
            
            pos = lower_bound(1 + all(arr), aver) - arr.begin();

            sum = pre[R] - pre[pos - 1] - aver * (R - pos + 1)
                    + aver * (pos - L) - (pre[pos - 1] - pre[L - 1]);

            // cout << l << " " << r << " " << mid << " " << aver << " " << L << " " << R << " " << sum << endl;

            if (sum <= m) { flag = true; res = max(len, res), l = mid + 1; continue; }

            if (flag) res = max(len, res), l = mid + 1;
            else r = mid - 1;

            #undef len
        }

        cout << res << endl;
    } else {
        for (int i = 1; i <= n; i ++ )
            pre[i] = pre[i - 1] + arr[i];

        int res = 0;

        int l = 0, r = n;

        while(l <= r) {
            int mid = l + r >> 1;

            #define len mid

            bool flag = false;

            for (int L = 1; L + len - 1 <= n; L ++ ) {
                int R = L + len - 1;
                int aver = (pre[R] - pre[L - 1]) / len;
                
                int pos = lower_bound(1 + all(arr), aver) - arr.begin();

                int sum = pre[R] - pre[pos - 1] - aver * (R - pos + 1)
                        + aver * (pos - L) - (pre[pos - 1] - pre[L - 1]);

                // cout << l << " " << r << " " << mid << " " << aver << " " << L << " " << R << " " << sum << endl;
                // cout << pre[R] - pre[pos - 1] - aver * (R - pos + 1) << " " << aver * (pos - L) - (pre[pos - 1] - pre[L - 1]) << endl;

                // cout << endl;

                if (sum <= m) { flag = true; break; }


                aver = (pre[R] - pre[L - 1] + len - 1) / len;
                
                pos = lower_bound(1 + all(arr), aver) - arr.begin();

                sum = pre[R] - pre[pos - 1] - aver * (R - pos + 1)
                        + aver * (pos - L) - (pre[pos - 1] - pre[L - 1]);

                // cout << l << " " << r << " " << mid << " " << aver << " " << L << " " << R << " " << sum << endl;

                if (sum <= m) { flag = true; break; }
            }

            if (flag) res = max(len, res), l = mid + 1;
            else r = mid - 1;

            #undef len
        }

        cout << res << endl;
    }
}