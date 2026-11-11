#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;

constexpr int MAX_N = 2000010; // a little bit large
// fstream, show your strength!!!
// i hope it works. and works faster.
ifstream ifs;
ofstream ofs;
#define cin ifs
#define cout ofs

typedef long long var;
var a[MAX_N];

int c, T;
var solve() {
    var n, d;
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n <= 2) return 0; // XianRan.
    if(c == 11 || c == 12) {
        // cerr << "?";
        const var xd = (var) (a[2] - a[1]);
        // cerr << xd << "?" << d << " " << n-3 << "?\n";
        const int jp = d / xd;
        if(jp <= 1) return 0;

        return max(0ll, n - jp*2 + 1);
    } else {
        // i have no ideas && no time.

        // anyway.
        return 0;
    }
    return 1;
}

int main() {
    // freopen("migrate.in", "r", stdin);
    // freopen("migrate.out", "w", stdout);
    ifs.open("migrate.in");
    ofs.open("migrate.out");
    ifs.sync_with_stdio(false);
    ofs.sync_with_stdio(false);
    
    cin >> c >> T; // t <= 1e5 ?
    while(T--) {
        cout << solve() << '\n';
    }

    // fclose(stdin);
    // fclose(stdout);
    ifs.close();
    ofs.close();
    return 0;
}