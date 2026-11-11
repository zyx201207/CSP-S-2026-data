#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
string ans = "";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    bool flag = 1;
    if(c1 == c2){
        ans += '1';
        for(int i=0;i<=1;i++){
            if(s1[i] != s2[i]){
                flag = 0;
                break;
            }
        }
        if(flag!=0){
            ans += '1';
            if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C'){
                ans += '1';
                if(s1[2]+1==s2[2] || s2[2]+1==s1[2])
                    ans += '1';
                else{
                    ans += '0';
                }
            }
            else if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F'){
                ans += "11";
            }
            else{
                ans += "00";
            }
        }
        else{
            ans += "000";
        }
    }
    else
        ans += "0000";
    cout << ans;
    return 0;
}
