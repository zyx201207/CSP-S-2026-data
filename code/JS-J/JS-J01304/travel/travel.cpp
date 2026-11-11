#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(string c1,string s1,string c2,string s2){
    if(!(c1 == c2 && s1[1] == s2[1] && s1[0] == s2[0])){
        return false;
    }
    if(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C'){
        return true;
    }
    if(s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'){
        return true;
    }
    return false;
}
bool check2(string c1,string s1,string c2,string s2){
    if(!check(c1,s1,c2,s2)){
        return false;
    }
    char z1 = s1[2],z2 = s2[2];
    if(z1 == 'A' && z2 == 'B'){
        return true;
    }
    if(z1 == 'B' && z2 == 'A'){
        return true;
    }
    if(z1 == 'C' && z2 == 'B'){
        return true;
    }
    if(z1 == 'B' && z2 == 'C'){
        return true;
    }
    if(z1 == 'D' && z2 == 'F'){
        return true;
    }
    if(z1 == 'F' && z2 == 'D'){
        return true;
    }
    return false;
}
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000";
        return 0;
    }
    cout << (c1 == c2);
    cout << (c1 == c2 && s1[1] == s2[1] && s1[0] == s2[0]);
    cout << check(c1,s1,c2,s2);
    cout << check2(c1,s1,c2,s2);
    return 0;
}
