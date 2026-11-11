#include <bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int num(string s){
    return (s[0] - '0') * 10 + (s[1] - '0');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> s1 >> b >> s2;
    if (a == b) cout << 1;
    else{
        cout << "0000";
        return 0;
    }
    if (num(s1) == num(s2)) cout << "1";
    else{
        cout << "000";
        return 0;
    }
    if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C' || s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F') cout << 1;
    else{
        cout << "00";
        return 0;
    }
    if (s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2] || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D') cout << 1;
    else{
        cout << 0;
        return 0;
    }
    return 0;
}
