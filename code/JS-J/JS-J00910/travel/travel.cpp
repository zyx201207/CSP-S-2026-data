#include <iostream>
using namespace std;
int main(){
    // abcdf
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2){
        cout << '1';
        if (s1.substr(0, 2) == s2.substr(0, 2)){
            cout << '1';
            bool r1, r2;
            r1 = (s1[2] == 'D' || s1[2] == 'F');
            r2 = (s2[2] == 'D' || s2[2] == 'F');
            if (r1 ^ r2 == 0){
                cout << '1';
                if(!((s1[2] == 'A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))){
                    cout << '1';
                }else{
                    cout << '0';
                }
            }else{
                cout << "00";
            }
        }else{
            cout << "000";
        }
    }else{
        cout << "0000";
    }
}
