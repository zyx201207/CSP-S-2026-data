#include<iostream>
#include<string>
using namespace std;

int toInt(string a) {
    int num = 0;
    num = a[0] * 10 + a[1];
    return num;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    bool f1 = false;
    cin >> c1 >> s1 >> c2 >> s2;
    cout << (c1 == c2);
    int n1 = toInt(s1), n2 = toInt(s2);
    if (c1 == c2) f1 = true;
    if (n1 == n2 && f1) {
        cout << 1;
    } else {
        cout << 0;
        f1 = false;
    }

    if (s1[2] >= 'D' && s2[2] >= 'D' && f1) {
        cout << 1;
    }
    else if (s1[2] < 'D' && s2[2] < 'D' && f1) {
        cout << 1;
    }
    else {
        cout << 0;
        f1 = false;
    }
    if (f1 && (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1)) {
        cout << 1;
    } else cout << 0;
    return 0;
}
