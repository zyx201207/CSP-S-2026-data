#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> c2 >> s1 >> s2;
    string ans;
    if(c1==s1){
        ans=ans+'1';
        if(c2[0]==s2[0]&&c2[1]==s2[1]){
            ans=ans+'1';
            if(c2[2]<='C'&&s2[2]<='C'){
                ans=ans+'1';
                if(abs(c2[2]-s2[2])==1){
                    ans=ans+'1';
                }
                else{
                    ans="1110";
                }
            }
            else if(c2[2]>='D'&&s2[2]>='D'){
                ans="1111";
            }
            else{
                ans="1100";
            }
        }
        else{
            ans="1000";
        }
    }
    else{
        ans="0000";
    }
    cout << ans << endl;
    return 0;
}
