#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string acar,aseat,bcar,bseat;
    int car = 0,seat = 0;
    cin >> acar >> aseat >> bcar >> bseat;
    if(acar == bcar){
        cout << '1';
        car = 1;
    }
    else{
        cout << '0';
    }
    if(car == 1){
        if(aseat[0] == bseat[0] && aseat[1] == bseat[1]){
            cout << '1';
            seat = 1;
        }
        else{
            cout << '0';
        }
    }
    else{
        cout << '0';
    }
    if(seat == 1){
        if(aseat[2] == 'A' || aseat[2] == 'B' || aseat[2] == 'C' && bseat[2] == 'A' || bseat[2] == 'B' || bseat[2] == 'C'){
            cout << '1';
        }
        else if(aseat[2] == 'D' || aseat[2] == 'F' && bseat[2] == 'D' || bseat[2] == 'F'){
            cout << '1';
        }
        else{
            cout << '0';
        }
    }
    else{
        cout << '0';
    }
    if(seat == 1 && aseat[2] == 'A' && bseat[2] == 'B' || aseat[2] == 'B' && bseat[2] == 'C' || aseat[2] == 'D' && bseat[2] == 'F'){
        cout << '1';
    }
    else if(seat == 1 && bseat[2] == 'A' && aseat[2] == 'B' || bseat[2] == 'B' && aseat[2] == 'C' || bseat[2] == 'D' && aseat[2] == 'F'){
        cout << '1';
    }
    else{
        cout << '0';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
