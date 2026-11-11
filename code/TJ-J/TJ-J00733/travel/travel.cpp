#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    char com1[3] = {'A', 'B', 'C'};
    bool s1l, s2l;
    int p1, p2;
    cin >> c1 >> s1 >> c2 >> s2;
    cout << (c1 == c2);
    p1 = s1[0] - '0' * 10 + s1[1] - '0';
    p2 = s2[0] - '0' * 10 + s2[1] - '0';
    cout << ((p1 == p2) && (c1 == c2));
    for (int i = 0; i < 3; i++){
        if(s1[2] == com1[i]){
            s1l = 1;
        }
        if(s2[2] == com1[i]){
            s2l = 1;
        }
    }
    cout << (((p1 == p2) && (s1l == s2l)) && (c1 == c2));
    if(((s1l == s2l) && (p1 == p2)) && (c1 == c2)){
        if(s1l){
            cout << ((((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C')) || (s1[2] == 'B' && s2[2] == 'A')) || (s1[2] == 'C' && s2[2] == 'B'));
        }
        else{
            cout << ((s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' || s2[2] == 'F'));
        }
    }
    else{
        cout << 0;
    }
    return 0;
}
