#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2; cin >> c1 >> s1 >> c2 >> s2;
    cout << (c1 == c2 ? 1 : 0);
    string a1 = "", a2 = "", b1 = "", b2 = "";
    for(int i= 0; i <= 2; i++) {
        if(i < 2) a1 += s1[i], a2 += s2[i];
        else b1 += s1[i], b2 += s2[i];
    }

    cout << (a1 == a2 ? 1 : 0);
    cout << (a1 == a2 && ((b1 == "A" && b2 == "B") || (b1 == "B" && b2 == "A") || (b1 == "C" && b2 == "D") || (b1 == "C" && b2 == "F") || (b1 == "D" && b2 == "F") || (b1 == "D" && b2 == "C") || (b1 == "F" && b2 == "C") || (b1 == "F" && b2 == "D")) ? 1 : 0);
    cout << (a1 == a2 && ((b1 == "A" && b2 == "B") || (b1 == "B" && b2 == "A") || (b1 == "C" && b2 == "D") || (b1 == "D" && b2 == "F") || (b1 == "D" && b2 == "C") || (b1 == "F" && b2 == "D")) ? 1 : 0);
    return 0;
}