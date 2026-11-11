#include<bits/stdc++.h>
using namespace std;
string c1 , s1 , c2 , s2 , ans = "";
long long n;
bool ok = 0 , ok2 = 0 , ok3 = 0;
bool tp(string s1 , string s2){
    bool a = 0 , b = 0;
    if(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C')a = 1;
    else if(s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')b = 1;
    if(a == 1 || b == 1)return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        ans += '1';
        ok = 1;
    }else ans += '0';
    if(s1[1] == s2[1] && s1[0] == s2[0] && ok == 1){
        ans += '1';
        ok2 = 1;
    }else ans += '0';
    if(tp(s1 , s2) == 1 && ok2 == 1){
        ans += '1';
        ok3 == 1;
    }else ans += '0';
        if((s1[2] == s2[2]-1 || s2[2] == s1[2]-1) && ok2 == 1)ans += '1';
        else ans += '0';
    cout << ans;
    return 0;
}

