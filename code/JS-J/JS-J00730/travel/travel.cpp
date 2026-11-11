#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 100007;

char ra, rb, rra, rrb, rrc;
char xa, xb, xxa, xxb, xxc;

bool isleft(char c) {
    if (c == 'A' || c == 'B' || c == 'C') return 1;
    else return 0;
}
bool chk(char s, char t) {
    if ((s == 'A' && t == 'B') || (s == 'B' && t == 'c') || (s == 'D' && t == 'F') ||
        (t == 'A' && s == 'B') || (t == 'B' && s == 'c') || (t == 'D' && s == 'F')) {
        return 1;
    }
    else
        return 0;
}

signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> ra >> rb >> rra >> rrb >> rrc >> xa >> xb >> xxa >> xxb >> xxc;
    bool a = 0, b = 0, c = 0, d = 0;
    if (ra == xa && rb == xb) {
        cout << 1;
        a = 1;
    }
    else {
        cout << 0;
    }
    if (rra ==xxa && rrb == xxb && a) {
        cout << 1;
        b = 1;
    }
    else {
        cout << 0;
    }
    if (isleft(rrc) == isleft(xxc) && a && b) {
        cout << 1;
        c = 1;
    }
    else {
        cout << 0;
    }
    if (chk(rrc, xxc) == 1 && a && b && c) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}

