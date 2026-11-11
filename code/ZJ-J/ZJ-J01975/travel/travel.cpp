#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2, a, ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    a =="ABCDF";
    if(c1 != c2){
        ans += "0000";
        cout << ans;
    }
    else{
        ans += "1";
        if(s1[1] == s2[1]&&s1[0] == s2[0]){
            ans += "1";
            if(s1[2] == a[0]||s1[2] == a[1]||s1[2] == a[2]){
                if(s2[2] == a[0]||s2[2] == a[1]||s2[2]== a[2]){
                    ans += "1";
                    if((s1[2] == a[0]&&s2[2] == a[1])||(s1[2] == a[1]&&(s2[2] == a[0]||s2[2] == a[2]))||(s1[2] == a[2]&&s2[2] == a[1])){
                        ans += "1";
                        cout << ans;
                    }
                    else{
                        ans += "0";
                        cout << ans;
                    }
                }
                else{
                    ans += "00";
                    cout << ans;
                }
            }
            else{
                if(s2[2] == a[3]||s2[2] == a[4]){
                    ans += "11";
                    cout << ans;
            }
                else{
                    ans += "00";
                    cout << ans;
                }
            }
        }
        else{
            ans += "000";
            cout << ans;
        }
    }
    return 0;
}
