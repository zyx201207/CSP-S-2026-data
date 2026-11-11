#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    bool flag1=0, flag2=0, flag3=0, flag0=0;
    if(c1 == c2) {
        flag0=1;
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            flag1 = 1;
            int l = 0, r = 0;
            if(s1[2] <= 'C') l++;
            else r++;
            if(s2[2] <='C') l++;
            else r++;
            if(l == 2 || r == 2) {
                flag2 = 1;
                if(abs(s1[2] - s2[2]) == 1) flag3 = 1;
            }
        }
    }
    if(flag0) cout << 1; else cout << 0;
    if(flag1) cout << 1; else cout << 0;
    if(flag2) cout << 1; else cout << 0;
    if(flag3) cout << 1; else cout << 0;

    return 0;
}
