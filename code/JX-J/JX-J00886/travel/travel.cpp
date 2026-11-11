#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
    }
    else{
        cout << "0000";
        return 0;
    }
    int a1 , a2;
    if(s1[0] == '0'){
        a1 = s1[1]-48;
    }
    else{
        a1 = (s1[0]-48)*10 + (s1[1]-48);
    }
    if(s2[0] == '0'){
        a2 = s2[1]-48;
    }
    else{
        a2 = (s2[0]-48)*10 + (s2[1]-48);
    }
    if(a1 == a2){
        cout << '1';
    }
    else{
        cout << "000";
        return 0;
    }
    int b1 , b2;
    b1 = int(s1[2]);
    b2 = int(s2[2]);
    if(((b1 == 65 || b1 == 66 || b1 == 67) && (b2 == 65 || b2 == 66 || b2 == 67)) || ((b1 == 68 || b1 == 69) && (b2 == 68 || b2 == 69))){
        cout << 1;
    }
    else{
        cout << "00";
        return 0;
    }
    if(b1 > b2)
    {
        int t;
        t = b2;
        b2 = b1;
        b1 = t;
    }
    if(b1 == b2-1 && b1 != 67){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
