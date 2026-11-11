#include <bits/stdc++.h>
using namespace std;

int a[100001];
int main() {

    freopen("and.in","r", stdin);
    freopen("and.out","w", stdout);

    int n;
    cin >> n;
    int m;
    cin >> m;

    int maxn = -10000;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }

    if (m == 1) cout << maxn;
    if (m == 2) {
        int maxnn = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                maxnn = max(maxnn, a[j] & a[i]);

            }
        }
        cout << maxnn;
    } else {
        cout << "I don't know how to solve it and now I can go back home";
    }

    return 0;
}
