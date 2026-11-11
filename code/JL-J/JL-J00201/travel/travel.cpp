#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int ans = c1 == c2;
    cout << ans;
    ans &= (s1[0] == s2[0]) && (s1[1] == s2[1]);
    cout << ans;
    ans &= ('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C') || ('D' <= s1[2] && s1[2] <= 'F' && 'D' <= s2[2] && s2[2] <= 'F');
    cout << ans;
    char t1 = s1[2], t2 = s2[2];
    if (t1 > t2)
        swap(t1, t2);
    ans &= (t1 == 'A' && t2 == 'B') || (t1 == 'B' && t2 == 'C') || (t1 == 'D' && t2 == 'F');
    cout << ans;
    return 0;
}
