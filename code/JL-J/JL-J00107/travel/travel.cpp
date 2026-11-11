#include<bits/stdc++.h>
using namespace std;

int main(){
    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << "1";
    }
    else{
        cout << "0";
    }
    string z1 = s1[1] + s1[2], z2 = s2[1] + s2[2];
    if(z1 == z2){
        cout << "1";
    }
    else{
        cout << "0";
    }
    if('s1[3]' <= 'C' && 's2[3]' <= 'C'){
        cout << "1";
        if('s1[3]' - 's2[3]' == 1 || 's2[3]' - 's1[3]' == 1){
            cout << "1";
        }
        else{
            cout << "0";
        }
    )
    else if('s1[3]' > 'C' && 's2[3]' > 'C'){
        cout << "11";
    }
    else{
        cout << "0";
    }
    return 0;
}
