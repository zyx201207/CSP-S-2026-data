#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, a1, a2;
char b1, b2;
int cnt[70];
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2){
        cout << "0000";
    }else{
        cout << 1;
        a1 = s1[0]; a1 += s1[1];
        a2 = s2[0]; a2 += s2[1];
        if (a1 != a2){
            cout << "000";
        }else{
            cout << 1;
            cnt['A'] = cnt['B'] = cnt['C'] = 0;
            cnt['D'] = cnt['E'] = 1;
            b1 = s1[2];
            b2 = s2[2];
            if (cnt[b1] != cnt[b2]){
                cout << "00";
            }else{
                cout << 1;
                if (b2 - b1 != 1){
                    cout << 0;
                }else{
                    cout << 1;
                }
            }
        }
    }
    return 0;
}
