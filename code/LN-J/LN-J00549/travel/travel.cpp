#include<bits/stdc++.h>
using namespace std;
bool tongce(string s1, string s2){
    char a = s1[2], b = s2[2];
    if((a == 'A' && b == 'B') || (a == 'A' && b == 'C') || (a == 'B' && b == 'C') || (b == 'A' && a == 'B') || (b == 'A' && a == 'C') || (b == 'B' && a == 'C')){
        return true;
    }
    if((a == 'D' && b == 'F') || (a == 'F' && b == 'D')){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000";
    }else{
        cout << "1";
        if(s1[0] != s2[0] || s1[1] != s2[1]){
            cout << "000";
        }else{
            cout << "1";
            if(!tongce(s1, s2)){
                cout << "00";
            }else{
                cout << "1";
                if(s1[2] >= 'A' && s1[2] <= 'C'){
                    int a = s1[2]-s2[2];
                    if(a == 1 || a == -1){
                        cout << "1";
                    }else{
                        cout << "0";
                    }
                }else{
                    cout << "1";
                }
            }
        }
    }
    return 0;
}
