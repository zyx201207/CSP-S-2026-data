#include <bits/stdc++.h>
#define debug(a) //a
using namespace std;
const int N = 2e5 + 5;
struct {
    int l; char c;
} s[N];
int L = 0, sf=0, se;
long long ans = 0;
int main() {
    ifstream cin("string.in");
    ofstream cout("string.out");
    int n;cin>>n;
    for (int i = 0 ; i < n ; i++) {
        cin >> s[i].l >> s[i].c;
        L++;
    }
    se = L-1;
    while (sf < se) {
        debug(cout << sf << "-" << se << ":";)
        if (s[sf].c != s[se].c) {
            debug(cout << "!";)
            int a;
            if (s[sf].l == s[se].l) {
            debug(cout << "=";)
                a = s[sf].l;
                sf++, se--;
            }
            else if (s[sf].l > s[se].l) {
            debug(cout << ">";)
                a = s[se].l;
                s[sf].l -= s[se].l;
                se--;
            }
            else {
            debug(cout << "<";)
                a = s[sf].l;
                s[se].l -= s[sf].l;
                sf++;
            }
            ans += a;
        }
        else {
            debug(cout << "=";)
            if (s[sf].l == s[se].l) {
            debug(cout << "=";)
                sf++, se--;
            }
            else if (s[sf].l > s[se].l) {
            debug(cout << ">";)
                s[sf].l -= s[se].l;
                se--;
            }
            else {
            debug(cout << "<";)
                s[se].l -= s[sf].l;
                sf++;
            }
        }
        debug(cout << "\n";)
    }
    cout << ans;
    return 0;
}
