#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    long long n, m;
    cin >> n >> m;

    vector<int>num;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }

    int ans = 0;
    typedef vector<int>::size_type vint;

    for (int i = 31; i >= 0; i--) {
        int base = ans + (1 << i);
        int cnt = 0;

        for(vint j = 0; j < num.size(); j++) {
            if ((base & num[j]) == base) {
                cnt++;

                if (cnt == m) {
                    break;
                }
            }
        }

        if (cnt == m) {
            ans = base;
        }
    }

    cout << ans << endl;

    return 0;
}
