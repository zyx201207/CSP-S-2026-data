#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int cy_count, op_count;
    cin >> cy_count >> op_count;
    int begin = cy_count / 2;

    vector<int> cys;
    int tc;
    for (int i = 0; i < cy_count; i++) {
        cin >> tc;
        cys.push_back(tc);
    }
    
    std::sort(cys.begin(), cys.end());

    int result = 0;
    int sum = 0;
    int prev = cy_count / 2;

    for (int i = prev; i < cy_count; i++) {
        int tmp = 0;
        sum = 0;
        for (int j = i; j >= 0; j--) {
            if (op_count >= (tmp + 1) * cys[i] - sum - cys[j]) {
                sum += cys[j];
            } else {
                break;
            }
            tmp++;
        }
        if (tmp > result) {
            result = tmp;
        }

        int p = cys[prev];
        for (int i = 0; i < cy_count - 1; i++) {

            cout << cys[i] << endl;
        }
        while ((prev <= cy_count - 1) && cys[prev] == p) {
            prev++;
        }
        // cout << prev << endl;
    }

    cout << result << endl;

    return 0;
}
