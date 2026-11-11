#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1, s1, c2, s2;
map<char, int> m;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << 1;
    else cout << 0;
    if(c1 == c2) {
        bool flag = true;
        for(int i = 0; i < s1.size() - 1; i ++) {
            if(s1[i] != s2[i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << 1;
            char a = s1[s1.size() - 1];
            char b = s2[s2.size() - 1];
            m['A'] = m['B'] = m['C'] = 1;
            m['D'] = m['F'] = 2;
            if(m[a] == m[b]) {
                cout << 1;
                if(a == 'F') a = 'E';
                if(b == 'F') b = 'E';
                if(abs(int(b) - int(a)) == 1) {
                    cout << 1;
                } else cout << 0;
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
            return 0;
        }
    } else cout << "000";
    return 0;
}
