#include <bits/stdc++.h>
using namespace std;
int a1, a2, num1, num2;
string s1, s2;
char c1, c2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a1 >> s1 >> a2 >> s2;
    num1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    num2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    c1 = s1[2];
    c2 = s2[2];
    if(a1 == a2){
        cout << 1;
        if(num1 == num2){
            cout << 1;
            if(c1 == 'A'){
                if(c2 == 'B'){
                    cout << "11";
                }
                else if(c2 == 'C'){
                    cout << "10";
                }
                else{
                    cout << "00";
                }
            }
            else if(c1 == 'B'){
                if(c2 == 'A' || c2 == 'C'){
                    cout << "11";
                }
                else{
                    cout << "00";
                }
            }
            else if(c1 == 'C'){
                if(c2 == 'B'){
                    cout << "11";
                }
                else if(c2 == 'A'){
                    cout << "10";
                }
                else{
                    cout << "00";
                }
            }
            else if(c1 == 'D'){
                if(c2 == 'E'){
                    cout << "11";
                }
                else{
                    cout << "00";
                }
            }
            else{
                if(c2 == 'D'){
                    cout << "11";
                }
                else{
                    cout << "00";
                }
            }
        }
        else{
            cout << "000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
