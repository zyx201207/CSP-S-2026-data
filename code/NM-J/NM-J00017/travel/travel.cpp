#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int a1, b1, a2, b2, ji, ji2;
int zhuan(string s){
    return (s[0] - '0') * 10 + s[1] - '0';
}
int pan(string s){
    return s[2] - 'A' + 1;
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    a1 = zhuan(c1);
    a2 = zhuan(c2);
    if(a1 != a2){
        cout << "0000";
        return 0;
    }
    cout << "1";
    if(s1[0] != s2[0] or s1[1] != s2[1]){
        cout << "000";
    }else{
        cout << "1";
        ji = pan(s1);
        ji2 = pan(s2);
        if(!((ji == 3 and ji2 == 4) or (ji == 4 and ji2 == 3))){
            cout << "1";
        }else{
            cout << "00";
            return 0;
        }
        if(ji - ji2 == 1 or ji2 - ji == 1){
            cout << "1";
        }else{
            cout << "0";
        }
    }
    return 0;
}
