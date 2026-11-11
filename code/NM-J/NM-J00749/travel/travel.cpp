#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1[3],s1[3],c2[3],s2[3];
    string ans[5];
    cin >> c1[0] >> s1[0] >> c2[0] >> s2[0];
    if(c1[0] == c2[0]){
        ans[0] = "1";
    }
    else{
        ans[0] = "0";
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]){
        ans[1] = "1";
    }
    else{
        ans[1] = "0";
    }
    for (int i = 0;i <= 3;i++){
        cout << ans[i];
    }
    return 0;
}
