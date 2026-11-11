#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << 1;
    } else {
        cout << 0;
    }

    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) {
        cout << 1;
    } else {
        cout << 0;
    }
    char s3 = s1[2], s4 = s2[2];
    int cnt = max(s3, s4), ans = min(s3, s4);
    if (s3 == 'C' && s4 == 'D' || s3 == 'D' || s4 == 'C') {
        cout << 0;
    } else if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ((cnt - ans == 2) || (cnt - ans == 1))){
        cout << 1;
    } else {
        cout << 0;
    }

    if (s3 == 'C' && s4 == 'D' || s3 == 'D' || s4 == 'C') {
        cout << 0;
    } else if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && cnt - ans == 1 && ((s3 != 'C' && s4 != 'D') || (s3 != 'D' && s4 != 'C')) && ((cnt - ans == 2) || (cnt - ans == 1
))) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
