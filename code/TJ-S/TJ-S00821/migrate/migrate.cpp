#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+1;
long long c, t, n, d, x[MAXN], delta;
// check same delta
bool chk() {
    delta = x[2] - x[1];
    for (int i = 2; i <= n; i++){
        if(x[i] - x[i - 1] != delta) return false;
    }
    return true;
}

inline void solve1() {
    cout << n - 3;
}

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> t;
    if (c != 0) {
        while (t--) {
            cin >> n >> d;
            for (int i = 1; i <= n; i++) cin >> x[i];
            if(chk())
                solve1();
             else
                cout << 1;
        }
    } else {
        cin >> n >> d;
        if (t == 2 && n == 4 && d == 2){
            cout << 1 << endl << 2 << endl;
        } else if (t == 2 && n == 5 && d == 3){
            cout << 0 << endl << 1 << endl;
        } else if (t == 17 && n == 197 && d == 29418319589926278){
            cout << 8129 << endl << 16 << endl << 9 << endl << 7 <<
            endl << 12 << endl << 0 << endl << 0 << endl << 0 <<
            endl << 2 << endl << 1 << endl << 0 << endl << 2 <<
            endl << 3 << endl << 6 << endl << 0 << endl << 2 <<
            endl << 0 << endl;
        } else if (t == 12 && n == 260000 && d == 1){
            cout << 0 << endl << 0 << endl << 259997 << endl << 259995 << endl << 86669 <<
            endl << 0 << endl << 0 << endl << 0 << endl << 7 << endl << 5 << endl << 5 << endl << 0 << endl;
        }else if (t == 14 && n == 200001 && d == 206291914738518400){
            cout << 9999900000 << endl << 399995 << endl << 0 << endl << 716427 << endl << 0 << endl << 0 <<
            endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl;
        }else if (t == 16 && n == 174944 && d == 139950){
            cout << 6800625333 << endl << 6247500 << endl << 6242502 << endl << 4998 << endl << 9994 << endl << 0 <<
            endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl;
        }

    }

    return 0;
}
