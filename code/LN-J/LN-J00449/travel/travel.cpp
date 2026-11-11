#include <bits/stdc++.h>
#define sfr return cout << "safe\n", 0;
#define sf_void return cout << "safe\n", void();
using namespace std;
using ll = long long;
using i128 = __int128;
#define FILEIO "travel"

int che1, che2;
string zuo1, zuo2;

auto main() -> signed {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> che1 >> zuo1 >> che2 >> zuo2;
    cout << (int) (che1 == che2) << (int) (che1 == che2 && zuo1[0] == zuo2[0] && zuo1[1] == zuo2[1])
         << (int) (che1 == che2 && zuo1[0] == zuo2[0] && zuo1[1] == zuo2[1] && (zuo1[2] <= 'C' && zuo2[2] <= 'C' || zuo1[2] >= 'D' && zuo2[2] >= 'D'))
         << (int) (che1 == che2 && zuo1[0] == zuo2[0] && zuo1[1] == zuo2[1] && ((zuo1[2] <= 'C' && zuo2[2] <= 'C' && abs(zuo1[2] - zuo2[2]) == 1) || (zuo1[2] >= 'D' && zuo2[2] >= 'D')));
}