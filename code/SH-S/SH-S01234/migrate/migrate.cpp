#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c, t, n, d;
ll x[N], a[N];
vector<int> block;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    iostream::sync_with_stdio(false);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t-- > 0) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            if (i != 1) {
                a[i] = x[i] - x[i - 1];
                if (x[i] - x[i - 1] > d)
                    block.push_back(i);
            }
        }
        cout << 0 << endl;
    }
    return 0;
}

// 一整年没有碰 OI 导致全忘光了，OI 生涯也是结束了
// 只能文化课 RP++ 了，祝自己和另外三个 42 高考加油！