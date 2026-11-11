#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
map<char, int> mp;
void init(){
    mp['A'] = mp['B'] = mp['C'] = 1;
    mp['D'] = mp['F'] = 2;
}
bool check(char a, char b) {
    return (a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F');
}
signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    init();
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
        cout << 1;
    else
        cout << 0;
    if (s1[0] == s2[0] && s1[1] == s2[1] && c1 == c2)
        cout << 1;
    else
        cout << 0;
    if (mp[s1[2]] == mp[s2[2]] && s1[0] == s2[0] && s1[1] == s2[1] && c1 == c2)
        cout << 1;
    else
        cout << 0;
    if ((check(s1[2], s2[2]) || check(s2[2], s1[2])) && (s1[0] == s2[0] && s1[1] == s2[1]) && c1 == c2)
        cout << 1;
    else
        cout << 0;
    return 0;
}
