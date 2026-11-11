#include <bits/stdc++.h>
using namespace std;
int trans1(string s){
    if (s[0] == 48){
        return s[1] - 48;
    }
    return s[1] - 38;
}
char trans2(string s){
    return s[2];
}
bool judge(char a,char b){
    if (a == 'A' || a == 'B' || a == 'C'){
        return (b == 'A' || b == 'B' || b == 'C');
    }
    return (b == 'D' || b == 'F');
}
bool judge1(char a,char b){
    if (a == 'A'){
        return (b == 'B');
    }
    if (a == 'B'){
        return (b == 'A' || b == 'C');
    }
    if (a == 'C'){
        return (b == 'B');
    }
    if (a == 'D'){
        return (b == 'F');
    }
    return (b == 'D');
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    int c1 = trans1(a),s11 = trans1(b),c2 = trans1(c),s21 = trans1(d);
    char s12 = trans2(b),s22 = trans2(d);
    if (c1 == c2){
        cout << 1;
    }
    else{
        cout << "0000";
        return 0;
    }
    if (s11 == s21){
        cout << 1;
    }
    else{
        cout << "000";
        return 0;
    }
    if (judge(s12,s22)){
        cout << 1;
    }
    else{
        cout << "00";
        return 0;
    }
    if (judge1(s12,s22)){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
