#include <bits/stdc++.h>
using namespace std;
int a[500005], f[500005], ans[300005]; //ans[] : 1~m's pai sum
vector <int> s;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) { // n games
        for (int j = i; j < n; j++) {  // dapai
            if (f[a[j] - 1] != 0) {  // 0 : no appeared
                while (true) {
                    if (s.back() == a[j]) {
                        s.pop_back();
                        break;
                    }
                    s.pop_back();
                }
            }

            s.push_back(a[j]);
            f[a[j] - 1]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 1 && s[i] <= m) {
                ans[s[i]]++;
            }
        }

        for (int i = 0; i < n; i++) {
            f[i] = 0;
        }


    }

    for (int i = 0; i < 300000; i++) {
        if (ans[i] != 0) {
            cout << ans[i] << ' ';
        }
    }
    return 0;
}
