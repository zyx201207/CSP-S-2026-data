#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
        int f = 0;
        for(int i = 0; i <= 1; i++) {
            if(s1[i] != s2[i]) {
                f = 1;
            }
        }
        if(f == 0) {
            if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
                if(int(s1[2]) + 1 == int(s2[2]) || int(s1[2]) - 1 == int(s2[2])) {
                    cout << "1111" << endl;
                    return 0;
                }else {
                    cout << "1110" << endl;
                    return 0;
                }
            }else {
                cout << "1100" << endl;
                return 0;
            }
        }else {
            cout << "1000" << endl;
            return 0;
        }
    }else {
        cout << "0000" << endl;
        return 0;
    }
    return 0;
}
