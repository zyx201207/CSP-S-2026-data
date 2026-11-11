#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int flag = 1;
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << '1';
    else{
            cout << "0000";
            return 0;
    }
    for(int i = 0;i <= 1;i++){
        if(s1[i] != s2 [i]){
                flag = 0;
                cout << "000";
                return 0;
        }
    }
    if(flag) cout << '1';
    char a = s1[2],b = s2[2];
    if(a >= 'A' && a <= 'C'){
        if(b >= 'A' && b <= 'C') cout << '1';
        else{
            cout << "00";
            return 0;
        }
    }else{
        if(b >= 'D' && b <= 'F') cout << '1';
        else{
            cout << "00";
            return 0;
        }
    }
    if(a + 1 - 0 == b || a - 1 - 0 == b) cout << '1';
    else cout << '0';
    return 0;
}
