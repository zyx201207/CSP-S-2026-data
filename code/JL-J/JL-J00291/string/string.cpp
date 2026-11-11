#include<bits/stdc++.h>
using namespace std;

int n, m, sum;
string a, t, t2;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> m >> a;
        for(int j = 1; j <= m; j++) {
            t = t + a;
            sum++;
        }
    }

    for(int j = sum-1; j >= 0; j--) {
        t2 = t2+t[j];
    }

    if(t==t2) {
        cout << "0";
    }
    else {
        cout << sum;
    }

    return 0;
}
