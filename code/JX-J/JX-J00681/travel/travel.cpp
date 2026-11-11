#include <bits/stdc++.h>

using namespace std;

bool sameside(char s1, char s2) {
    if ((s1 == 'A' && s2 == 'B') || (s1 == 'A' && s2 == 'C') || (s1 == 'B' && s2 == 'C') || (s1 == 'D' && s2 == 'F') ||
        (s1 == 'B' && s2 == 'A') || (s1 == 'C' && s2 == 'A') || (s1 == 'C' && s2 == 'B') || (s1 == 'F' && s2 == 'D')) {
        return 1;
    }
    return 0;
}

bool beside(char s1, char s2) {
    if ((s1 == 'A' && s2 == 'B') || (s1 == 'B' && s2 == 'C') || (s1 == 'D' && s2 == 'F') ||
        (s1 == 'B' && s2 == 'A') || (s1 == 'C' && s2 == 'B') || (s1 == 'F' && s2 == 'D')) {
        return 1;
    }
    return 0;
}

string n1, s1, n2, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> n1 >> s1 >> n2 >> s2;

    if (n1 == n2) {
        cout << "1";
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            cout << "1";
            if (sameside(s1[2], s2[2])) {
                cout << "1";
                if (beside(s1[2], s2[2])) {
                    cout << "1";
                } else cout << "0";
            } else cout << "00";
        } else cout << "000";
    } else cout << "0000";

    return 0;
}



