#include<bits/stdc++.h>
using namespace std;
bool pd(char c1,char c2){
    char da = max(c1,c2),xiao = min(c1,c2);
    c1 = da;c2 = xiao;
    if(c1 == 'D' || c1 == 'E'){
        if(c2 == 'A' || c2 == 'B' || c2 == 'C'){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000";
        return 0;
    }
    else {
        cout << "1";
        //string s11 = s1[0]+s1[1], s21 = s2[0]+s2[1];
        char p1 = s1[2],p2 = s2[2];
        if(s1[0] != s2[0] || s1[1] != s2[1]){
            cout << "000";
            return 0;
        }
        else {
            cout << "1";
            if(pd(p1,p2) == false){
                cout << "00";
                return 0;
            }
            else {
                cout << "1";
                if(abs(p1-p2) != 1){
                    cout << 0;
                    return 0;
                }
                else {
                    cout << "1";
                }
            }
        }
    }
    return 0;
}
