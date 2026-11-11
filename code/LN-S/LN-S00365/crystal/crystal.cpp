#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,m,a[676767],b[676767],c[676767],s = 1,l,t;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i < n;i ++) {
        scanf("%lld",&a[i]);
    }
    sort(a,a + n);
    if (a[0] < 0) {
        t = -a[0];
    }
    a[0] += t;
    b[1] = a[0];
    for (int i = 1;i < n;i ++) {
        a[i] += t;
        b[i + 1] += b[i] + a[i];
        if (i - l + 1 > s) {
            if ((a[i] * (i - l)) - (b[i] - b[l]) <= m) {
                s = i - l + 1;
                // clog << i << ' ' << l << ' ' << a[i] << ' ' << a[l] << ' ' << b[i] << ' ' << b[l] <<  ' ' << s << endl;
            } else {
                l ++;
            }
        }
        // clog << a[i] * i - b[i - 1] << endl;
    }
    /*
    clog << endl;
    for (int i = 0;i < n;i ++) {
        clog << a[i] << ' ' << b[i] << endl;
    }
    */
    cout << s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
