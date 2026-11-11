#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    long long count;
    char ch;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    vector<Segment> segs(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].count >> segs[i].ch;
    }

    long long ans = 0;
    int left_idx = 0;
    int right_idx = n - 1;
    long long left_rem = (n > 0) ? segs[0].count : 0;
    long long right_rem = (n > 0) ? segs[n - 1].count : 0;
    while (left_idx < right_idx) {
        long long k = min(left_rem, right_rem);
        if (segs[left_idx].ch != segs[right_idx].ch) {
            ans += k;
        }
        left_rem -= k;
        right_rem -= k;
        if (left_rem == 0) {
            left_idx++;
            if (left_idx <= right_idx) {
                left_rem = segs[left_idx].count;
            }
        }
        if (right_rem == 0) {
            right_idx--;
            if (right_idx >= left_idx) {
                right_rem = segs[right_idx].count;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
