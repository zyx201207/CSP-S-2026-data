#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    if (!(cin >> n)) return 0;
    vector<char> chars(n);
    vector<long long> counts(n);

    for (int i = 0; i < n; ++i) {
        cin >> counts[i] >> chars[i];
    }
    long long ans = 0;
    int left = 0;
    int right = n - 1;
    long long left_rem = counts[left];
    long long right_rem = counts[right];

    while (left < right) {
        if (chars[left] == chars[right]) {
            if (left_rem < right_rem) {
                right_rem -= left_rem;
                left++;
                if (left <= right) left_rem = counts[left];
            } else if (left_rem > right_rem) {
                left_rem -= right_rem;
                right--;
                if (right >= left) right_rem = counts[right];
            } else {
                left++;
                right--;
                if (left <= right) {
                    left_rem = counts[left];
                    right_rem = counts[right];
                }
            }
        } else {
            long long match_len = min(left_rem, right_rem);
            ans += match_len;
            if (left_rem < right_rem) {
                right_rem -= left_rem;
                left++;
                if (left <= right) left_rem = counts[left];
            } else if (left_rem > right_rem) {
                left_rem -= right_rem;
                right--;
                if (right >= left) right_rem = counts[right];
            } else {
                left++;
                right--;
                if (left <= right) {
                    left_rem = counts[left];
                    right_rem = counts[right];
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}

