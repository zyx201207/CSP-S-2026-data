#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
string num1, s1, num2, s2;
int ans[5];
bool flag = 0;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> num1 >> s1 >> num2 >> s2;
    if (num1 == num2) {
        ans[1] = 1;
    }
    if (s1.substr(0, 2) == s2.substr(0, 2)) {
        ans[2] = 1;
    }

    if (s1[2] - 'A' < 3 && s2[2] - 'A' < 3) {
        ans[3] = 1;
    } else if(s1[2] -'A' > 2 && s2[2] - 'A' > 2) {
        ans[3] = 1;
    }

    if ((s1[2] - 'A') - (s2[2] - 'A') == 1 || (s1[2] - 'A') - (s2[2] - 'A') == -1) {
        ans[4] = 1;
    }
    for (int i = 1; i <= 4; i++) {
        if (flag == 1) {
            cout << 0;
        } else {
            cout << ans[i];
        }
        if (ans[i] == 0) {
            flag = 1;
        }
    }
    cout << endl;
    return 0;
}
/*
*/
