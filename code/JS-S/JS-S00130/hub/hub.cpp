#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define getchar getchar_unlocked

void read(int &x) {
    bool flag = 0; int res = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') flag = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        res *= 10;
        res += c - '0';
        c = getchar();
    }
    x = (flag?-res:res);
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;read(c), read(t);
    while (t--) cout << 0 << endl;
    

    return 0;
}
/*
{crystal 100 Compile successfully
101 10 0.004 Right Output!!!
101 10 0.002 Right Output!!!
101 10 0.006 Right Output!!!
101 10 0.069 Right Output!!!
}102 40
{subway 100 Compile successfully
101 10 0.028 Right Output!!!
101 10 0.017 Right Output!!!
101 10 0.021 Right Output!!!
-103 0 3.082 Time out.
101 10 0.913 Right Output!!!
-103 0 3.067 Time out.
-103 0 3.076 Time out.
}102 40
*/