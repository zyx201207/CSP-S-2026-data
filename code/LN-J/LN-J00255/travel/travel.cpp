#include<iostream>
using namespace std;
string c1,s1,c2,s2;
bool an1,an2,an3,an4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2){
        an1 = true;
    }
    if (an1 == true && s1[1] == s2[1]){
        an2 = true;
    }
    if (an1 == true && an2 == true && ((s1[2] <= 'C' &&  s2[2] <='C') || (s1[2] > 'C' && s1[2] <= 'F' && s2[2] >'C' && s2[2] <= 'F'))){
        an3 = true;
    }
    if (an1 == true && an2 == true && abs(s1[2] - s2[2]) == 1){
        if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C')){

        }
        else{
            an4 = true;
        }
    }
    cout <<an1 << an2 << an3 << an4;
    return 0;
}
