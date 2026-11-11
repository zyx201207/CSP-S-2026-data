#include <bits/stdc++.h>

using namespace std;

int tr, ts;  // train
char sr[3], ss[3];  // seat
bool flag = 1;

bool is_diffside(char a, char b) {
    if (a == 'D' || a == 'F') {
        if (b == 'D' || b == 'F') {
            return 0;
        }
        return 1;
    }
    if (b != 'D' && b != 'F') {
        return 0;
    }
    return 1;
}

bool is_splited(char a, char b) {
    if (a == 'F') --a;
    if (b == 'F') --b;
    if (a - b == 1 || a - b == -1) return 0;
    return 1;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);

    cin >> tr;
    cin >> sr;
    cin >> ts;
    cin >> ss;

    if (tr != ts) {
        cout << "0000"; flag = 0;
    } else if (sr[0] != ss[0] || sr[1] != ss[1]) {
        cout << "1000"; flag = 0;
    } else if (is_diffside(sr[2], ss[2])) {
        cout << "1100"; flag = 0;
    } else if (is_splited(sr[2], ss[2])) {
        cout << "1110"; flag = 0;
    }

    if (flag) cout << "1111";

    return 0;
}
