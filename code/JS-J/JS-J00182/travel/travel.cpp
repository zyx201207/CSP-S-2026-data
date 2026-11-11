#include <bits/stdc++.h>
using namespace std;
bool f1(string s1 , string s2){
    return ((s1[0] == s2[0]) && (s1[1] == s2[1]));
}
bool f2(string s1 , string s2){
    return ((s1[2] >= 'D' && s2[2] >= 'D') || (s1[2] <= 'C' && s2[2] <= 'C'));
}
bool f3(string s1 , string s2){
    return (!((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A')));
}
int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    string a , b , c , d;
    cin >> a >> b >> c >> d;
    if (a == c){
        cout << 1;
        if (f1(b , c)){
            cout << 1;
            if (f2(b , c)){
                cout << 1;
                if (f3(b , c)) cout << 1;
                else cout << 0;
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
