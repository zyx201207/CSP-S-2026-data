#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << "1";
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout << "1";
            if((char)s1[2]-'C'>0 && (char)s2[2]-'C'>0){
                cout << "11";
                return 0;
            }
            else if((char)s1[2] =='A' && (char)s2[2] == 'C'){
                cout << "10";
                return 0;
            }
            else if((char)s1[2] =='C' && (char)s2[2] == 'A'){
                cout << "10";
                return 0;
            }
            else if((char)s1[2] =='C' && (char)s2[2] == 'D'){
                cout << "00";
                return 0;
            }
            else if((char)s1[2] =='D' && (char)s2[2] == 'C'){
                cout << "00";
                return 0;
            }
            else if(((char)s1[2]-'A') - ((char)s2[2]-'A') == 1 ||((char)s2[2]-'A') - ((char)s1[2]-'A') == 1){
                cout << "11";
                return 0;
            }
            else{
                cout << "00";
                return 0;
            }
        }
        else{
            cout << "000";
            return 0;
        }
    }
    else{
        cout << "0000";
        return 0;
    }

    return 0;
}
