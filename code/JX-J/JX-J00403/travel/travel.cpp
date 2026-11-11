#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    for(int i=0; i<2; i++){
        if(c1[i] != c2[i]){
            cout << "0000";
            return 0;
        }
    }
    cout << "1";
    for(int i=0; i<2; i++){
        if(s1[i] != s2[i]){
            cout << "000";
            return 0;
        }
    }
    cout << "1";
    if(s1[2] >= 'E' && s1[2] <= 'F' && s2[2] >= 'E' && s2[2] <= 'F') cout << "11";
    else if(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C'){
        if(char(s1[2]+1) == s2[2] || char(s1[2]-1) == s2[2]) cout << "11";
        else cout << "10";
    }
    else cout << "00";
    return 0;
}

