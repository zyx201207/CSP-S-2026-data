#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

string check(string c1,string s1,string c2,string s2){
    string ans = "";
    if(c1 == c2)    ans += '1';
    else    ans += '0';

    if(s1[0] + s1[1] == s2[0] + s2[1] && c1 == c2)    ans += '1';
    else    ans += '0';

    char t1 = s1[2],t2 = s2[2];
    if(t1 >= 'A' && t1 <= 'C' && t2 >= 'A' && t2 <= 'C' && s1[0] + s1[1] == s2[0] + s2[1] && c1 == c2)   ans += '1';
    else if(t1 == 'D' || t1 == 'F' && t2 == 'D' || t2 == 'F' && s1[0] + s1[1] == s2[0] + s2[1] && c1 == c2)   ans += '1';
    else    ans += '0';

    if(t1 >= 'A' && t1 <= 'C' && t2 >= 'A' && t2 <= 'C' && abs(t1 - t2) == 1 && s1[0] + s1[1] == s2[0] + s2[1] && c1 == c2)   ans += '1';
    else if(t1 == 'D' || t1 == 'F' && t2 == 'D' || t2 == 'F' && s1[0] + s1[1] == s2[0] + s2[1] && c1 == c2)   ans += '1';
    else    ans += '0';

    return ans;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    cout << check(c1,s1,c2,s2);
    return 0;
}
