#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    string ans = "";
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) ans += "1";
    else if(c1 != c2){
        cout << "0000";
        return 0;
    }
    if(s1[1] == s2[1]) ans += "1";
    else if(s1[1] != s2[1]){
        ans += "000";
        cout << ans;
        return 0;
    }
    if((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'E' && s2[2] >= 'D' && s2[2] <= 'E')) ans += "1";
    else if(!(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'E' && s2[2] >= 'D' && s2[2] <= 'E')){
        ans += "00";
        cout << ans;
        return 0;
    }
    if((s1[2] == 'A' && s2[2] == 'C') || (s2[2] == 'A' && s1[2] == 'C')){
            ans += "0";
            cout << ans;
            return 0;
    }
    else if(!(s1[2] == 'A' && s2[2] == 'C') || (s2[2] == 'A' && s1[2] == 'C')) ans += "1";
    cout << ans;


    return 0;
}
