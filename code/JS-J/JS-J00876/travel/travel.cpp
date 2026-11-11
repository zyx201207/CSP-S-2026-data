#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin >> s1 >> s2 >> c1 >> c2;
    int sc = (s1[0] - '0') * 10 + s1[1] - '0',cc = (c1[0] - '0') * 10 + c1[1] - '0',sr = (s2[0] - '0') * 10 + s2[1] - '0',cr = (c2[0] - '0') * 10 + c2[1] - '0',ss = s2[2] - 'A' + 1,cs = c2[2] - 'A' + 1;
    if(s2[2] == 'D'){
        ss++;
    }
    if(c2[2] == 'D'){
        cs++;
    }
    if(sc == cc){
        cout << 1;
        if(sr == cr){
            cout << 1;
            if(ss <= 3 && cs <= 3 || ss >= 5 && cs >= 5){
                cout << 1;
                if(abs(ss - cs) == 1){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            else{
                cout << "00";
            }
        }
        else{
            cout << "000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
