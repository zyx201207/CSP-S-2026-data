#include<bits/stdc++.h>
using namespace std;
string n1 , k1;
string n2 , k2;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> n1 >> k1 >> n2 >> k2;
    if(n1 != n2){
        cout << "0000";
    }
    else{
        cout << '1';
        int i = int(k1[0]) * 10 + int(k1[1]);
        int j = int(k2[0]) * 10 + int(k2[1]);
        if(i != j){
            cout << "000";
        }
        else{
            cout << '1';
            bool a , b;
            //t右f左
            a = false;
            b = false;
            if(k1[2] == 'D' || k1[2] == 'F'){
                a = true;
            }
            if(k2[2] == 'D' || k2[2] == 'F'){
                b = true;
            }
            if(a != b){
                cout << "00";
            }
            else{
                cout << '1';
                if(k1[2] == 'A' && k2[2] == 'B' || k1[2] == 'B' && k2[2] == 'A'){
                    cout << '1';
                }
                else if(k1[2] == 'B' && k2[2] == 'C' || k1[2] == 'C' && k2[2] == 'B'){
                    cout << '1';
                }
                else if(k1[2] == 'D' && k2[2] == 'F' || k1[2] == 'F' && k2[2] == 'D'){
                    cout << '1';
                }
                else{
                    cout << '0';
                }
            }

        }
    }
    return 0;
}