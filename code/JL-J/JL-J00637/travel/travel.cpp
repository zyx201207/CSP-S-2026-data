#include<bits/stdc++.h>
using namespace std;
string rrtool(char t1,char t2){
    if(t1 >= 'A' && t1 <= 'C' && (t2 == 'D' || t2 == 'F')){
        return "1100";
    }
    if(t2 >= 'A' && t2 <= 'C' && (t1 == 'D' || t1 == 'F')){
        return "1100";
    }
    if(t1 == 'A' && t2 == 'C'){
        return "1110";
    }
    if(t2 == 'A' && t1 == 'C'){
        return "1110";
    }
    return "1111";
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000";
    }
    else{
        if(s1[0] != s2[0] || s1[1] != s2[1]){
            cout << "1000";
        }
        else{
            cout << rrtool(s1[2],s2[2]);
        }
    }
    return 0;
}
