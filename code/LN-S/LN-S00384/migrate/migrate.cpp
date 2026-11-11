#include<bits/stdc++.h>
using namespace std;
int x[50000000] = {};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for (int h = 1 ; h <= t ; h++) {
        int n = 0;
        long long d = 0;
        cin >> n;
        cin >> d;
        for (int i = 1 ; i <= n ; i++) {
            if (x[i] != 0) {
                x[i] = 0;
            }
            cin >> x[i];
        }
        long long mink = 0;
        for (int i = 1 ; i <= n ; i++) {
            long long k = x[i + 1] - x[i];
            mink = min(mink,k);
        }
        if (mink > d) {
            cout << "0" << endl;
            continue;
        }
        if (n % 2 == 0 && d % 2 == 0) {
            cout << "1" << endl;
            continue;
        } else {
            cout << "2" << endl;
            continue;
        }
    }
    return 0;
}