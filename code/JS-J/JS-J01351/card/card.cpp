#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[500005];
int b[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = 0;
    }
    for(int i = 1; i <= n; i++) {
        int l = i, r = i + 1;
        while(r <= n) {
            if(a[l].first == a[r].first) {
                //cout << l << " " << r << endl;
                for(int j = l; j <= r - 1; j++) {
                    a[j].second = 1;
                }
                l = r;
                //cout << l << " " << r << endl;
            }
            r++;
        }
        for(int j = i; j <= n; j++) {
            //cout << a[i].second << " " << j << endl;
            if(a[i].second == 0) {
                b[a[i].first]++;
            }
        }
        for(int i = 1; i <= n; i++) {
            a[i].second = 0;
        }
    }
    for(int i = 1; i <= m; i++) {
        cout << b[i] << endl;
    }
    return 0;
}
