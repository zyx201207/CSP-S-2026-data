#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << "1";
    } else {
        cout << "0000";
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]){
        cout << "1";
    } else {
        cout << "000";
        return 0;
    }
    if(((s1[2] >= 'A' and s1[2] <= 'C') and (s2[2] >= 'A' and s2[2] <= 'C')) or ((s1[2] >= 'D' and s1[2] <= 'E') and (s2[2] >= 'D' and s2[2] <= 'E'))){
        cout << "1";
    } else {
        cout << "00";
        return 0;
    }
    bool flag = true;
    if(int(s1[2]) - int(s2[2]) == 1 && s1[2] != 0){
        cout << "1";
        flag = false;
    }
    if(int(s2[2]) - int(s1[2]) == 1 && s2[2] != 0){
        cout << "1";
        flag = false;
    }
    if(flag){
        cout << "0";
    }
    return 0;
}
