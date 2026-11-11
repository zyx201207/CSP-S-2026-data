#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
string c1, s2, c3, s4;
int a = 0, b = 0;
cin >> c1 >> s2 >> c3 >> s4;
for (int i = 1; i <= s2.size(); i ++){
    if (isdigit(s2[i])){
        a += s2[i] - '0';
    }
}
for (int i = 1; i <= s4.size(); i ++){
    if (isdigit(s4[i])){
        b += s4[i] - '0';
    }
}
   if (c1 == c3){
        cout << "1";
   } else {
        cout << "0";
   }
    if (a == b){
        cout << "1";
   } else {
        cout << "0";
   }
   if ((s2[2] <= 'C' && s4[2] <= 'C') || (s2[2] >= 'D' && s4[2] >= 'D')){
        cout << "1";
   } else {
        cout << "0";
   }
   if (s4[3] - s2[3] == 1 && (s4[2] != 'C' && s2[2] != 'D') || (s4[2] != 'D' && s2[2] != 'C')){
        cout << "1";
   }else{
        cout << "0";
   }
return 0;
}
