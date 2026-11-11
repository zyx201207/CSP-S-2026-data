#include<bits/stdc++.h>
using namespace std;
string a1, a2, b1, b2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    bool same_car, same_row, same_ce, together;
    if (a1 == b1){
        same_car = true;
        if (a2[0] == b2[0] && a2[1] == b2[1]){
            same_row = true;
            if (a2[2] == 'A'){
                if (b2[2] == 'B'){
                    same_ce = true;
                    together = true;
                }else if (b2[2] == 'C'){
                    same_ce = true;
                    together = false;
                }else{
                    same_ce = false;
                    together = false;
                }
            }else if (a2[2] == 'B'){
                if (b2[2] == 'A' || b2[2] == 'C'){
                    same_ce = true;
                    together = true;
                }else{
                    same_ce = false;
                    together = false;
                }
            }else if (a2[2] == 'C'){
                if (b2[2] == 'A'){
                    same_ce = true;
                    together = false;
                }else if (b2[2] == 'B'){
                    same_ce = true;
                    together = true;
                }else{
                    same_ce = false;
                    together = false;
                }
            }else if (a2[2] == 'D'){
                if (b2[2] == 'F'){
                    same_ce = true;
                    together = true;

                }else{
                    same_ce = false;
                    together = false;
                }
            }else{
                if (b2[2] == 'D'){
                    same_ce = true;
                    together = true;
                }else{
                    same_ce = false;
                    together = false;
                }
            }
        }else{
            same_row = false;
            same_ce = false;
            together = false;
        }
    }else{
        same_car = false;
        same_ce = false;
        same_row = false;
        together = false;
    }
    cout << int(same_car) << int(same_row) << int(same_ce) << int(together) << "\n";
    return 0;
}
