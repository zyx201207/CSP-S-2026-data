#include <bits/stdc++.h>
#define debug(a) //a
using namespace std;
const int N = 5e5 + 5;
int n;
long long m;
long long a[N], awa[N];
bool check(int p) {
    long long rm=m;
    for (int i = 1 ; i <= p ; i++)
        awa[i] = a[p]-a[i];
    for (int i = 1 ; i <= p ; i++) {
        if (rm < awa[i]) {
            debug(cout << p << ":false\n";)
            return false;
        }
        debug(cout << awa[i] << ",";)
        rm -= awa[i];
    }
    debug(cout << p << ":" << (m - rm) << endl;)
    return true;
}
int search() {
    int l=1, r=n;
    int mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        debug(cout << "check[" << l << "<" << mid << ">" << r << "]";)
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main() {
    ifstream cin("crystal.in");
    ofstream cout("crystal.out");
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    cout << search();
    return 0;
}
