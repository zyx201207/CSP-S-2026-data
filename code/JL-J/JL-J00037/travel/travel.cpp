#include <bits/stdc++.h>
using namespace std;
bool aa(char a, char b) {
    string left = "ABC";
    string right = "DF";
    if (a > b) swap(a, b);
    if (left.find(a) != string::npos && left.find(b) != string::npos) {
        return (b - a == 1);
    }
    if (right.find(a) != string::npos && right.find(b) != string::npos) {
        if (a == 'D' && b == 'F') return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1, c2;
    string s1, s2;
    if (!(cin >> c1 >> s1 >> c2 >> s2)) return 0;
    bool ge = (c1 == c2);
    string row1 = s1.substr(0, s1.length() - 1);
    string row2 = s2.substr(0, s2.length() - 1);
    bool bb = ge && (row1 == row2);
    char seat1 = s1.back();
    char seat2 = s2.back();
    string left = "ABC";
    string right = "DF";
    bool de = false;
    if (bb) {
        bool l1 = (left.find(seat1) != string::npos);
        bool l2 = (left.find(seat2) != string::npos);
        bool r1 = (right.find(seat1) != string::npos);
        bool r2 = (right.find(seat2) != string::npos);

        if ((l1 && l2) || (r1 && r2)) {
            de = true;
        }
    }
    bool nt = de && aa(seat1, seat2);
    cout << (ge ? "1":"0");
    cout << (bb ? "1" : "0");
    cout << (de ? "1" : "0");
    cout << (nt ? "1" : "0");

    return 0;
}
