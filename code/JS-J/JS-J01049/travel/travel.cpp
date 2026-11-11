#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c1, s1, c2, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    char x1 = s1[2], x2 = s2[2];
    if(c1 == c2){
        cout << 1;
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout << 1;
            if(x1 == 'A'){
                if(x2 == 'B'){
                    cout << "11";
                }
                else if(x2 == 'C'){
                    cout << "10";
                }
                else{
                    cout << "00";
                }
            }
            if(x1 == 'B'){
                if(x2 == 'A'){
                    cout << "11";
                }
                else if(x2 == 'C'){
                    cout << "11";
                }
                else{
                    cout << "00";
                }
            }
            if(x1 == 'C'){
                if(x2 == 'A'){
                    cout << "10";
                }
                else if(x2 == 'B'){
                    cout << "11";
                }
                else{
                    cout << "00";
                }
            }
            if(x1 == 'D'){
                if(x2 == 'F'){
                    cout << "11";
                }
                else{
                    cout << "00";
                }
            }
            if(x1 == 'F'){
                if(x2 == 'D'){
                    cout << "11";
                }
                else{
                    cout << "00";
                }
            }
        }
        else
            cout << "000";
    }
    else
        cout << "0000";

    return 0;
}
