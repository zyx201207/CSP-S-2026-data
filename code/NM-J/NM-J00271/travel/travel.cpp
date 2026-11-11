#include <bits/stdc++.h>
using namespace std;
string c2[1] , c4[1];
int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    string c1 , c3;
    cin >> c1;
    for(int i = 0 ; i < 1 ; i++){
        cin >>c2[i];
    }
    cin >> c3;
    for(int i = 0 ; i < 1 ; i++){
        cin >> c4[i];
    }
    if(c1 == c3 && c1 != "01" && c1 != "16" && c3 != "01" && c3 != "16"){
        cout << '1';
    }
    else if(c1 != c3){
       cout << '0';
    }
    if(c2[1] == c4[1] && c2[2] == c4[2]){
        cout << '1';
    }
    else if(c2[1] != c4[1] || c2[2] != c4[2]){
        cout << '0';
    }
    if (c2[3] >= "A" && c2[3] <= "C" && c4[3] >= "A" && c4[3] <= "C" || c2[3] >= "D" && c2[3] <= "F" && c4[3] >= "F" && c4[3] <= "D"){
        cout << '1';
    }
    else {
       cout << '0';
    }
    if(c2[3] == "A" && c2[3] == "B" || c2[3] == "B" && c2[3] == "A" || c2[3] == "B" && c2[3] == "C" || c2[3] == "C" && c2[3] == "B" || c2[3] == "D" && c2[3] == "F" || c2[3] == "F" && c2[3] == "D"){
        cout << '1';
    }
    else{
        cout << '0';
    }
    return 0;
}
