#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2;
// char[5] ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000";
        return 0;
    }
    if(s1[0] != s2[0] || s1[1] != s2[1]){
        cout << "1000";
        return 0;
    }
    if(s1[2] - '0' >= 17 && s1[2] - '0' <= 19 && s2[2] - '0' >= 20 && s2[2] - '0' <= 21){
        cout << "1100";
        return 0;
    }
    if(s2[2] - '0' >= 17 && s2[2] - '0' <= 19 && s1[2] - '0' >= 20 && s1[2] - '0' <= 21){
        cout << "1100";
        return 0;
    }
    if(abs((s1[2] - '0') - (s2[2] - '0')) != 1){
        cout << "1110";
        return 0;
    }
    cout << "1111";
}