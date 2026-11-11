#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    map<char, int> p;
    p['A'] = 1;
    p['B'] = 2;
    p['C'] = 3;
    p['D'] = 8;
    p['F'] = 9;
    if(c1 == c2){
        cout << "1";
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout << "1";
            if(abs(p[s1[2]] - p[s2[2]]) <= 2){
                cout << "1";
                if(abs(p[s1[2]] - p[s2[2]]) == 1) cout << "1";
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";

    return 0;
}
