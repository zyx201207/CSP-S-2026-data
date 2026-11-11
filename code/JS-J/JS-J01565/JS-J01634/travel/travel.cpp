#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout << 1;
            char v1 = s1[2] , v2 = s2[2];
            if(v1 > v2){
                swap(v1 , v2);
            }
            if((v1 <= 'C' && v2 <= 'C') || (v1 >= 'D' && v2 >= 'D')){
                cout << 1;
                if(v2 == v1 + 1 || v1 == 'D'){
                    cout << 1;
                }
                else{
                    cout << '0';
                }
            }
            else{
                cout << "00";
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
