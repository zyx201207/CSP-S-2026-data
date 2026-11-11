#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 100001;

int n, m;
int a[N * 2], cnt[N];


signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int st = 1; st <= n; st++) {
        int it = n, val = a[n];
        while (it >= st) {

            for (int i = st; i <= n; i++) {
                if (i == it) {
                    cnt[val]++;
                    it--;
                    break;
                }
                else {
                    if (a[i] == val) {
                        cnt[val]++;
                        if (i == st) {
                            it = st - 1;
                            break;
                        }
                        else {
                            it = i - 1;
                            val = a[it];
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}

/*
3 1 2 1 3 2 3 1 2 1
3 1


*/
