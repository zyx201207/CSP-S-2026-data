#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2, s;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2){
        s+='1';
        if (s1[0] == s2[0] && s1[1] == s2[1]){
            s+='1';
            if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
                s+='1';
                if (abs(s1[2]-s2[2]) == 1){
                    s+='1';
                    cout << s;
                    return 0;
                }
                else{
                    s+='0';
                    cout << s;
                    return 0;
                }
            }
            else if ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')){
                s+='1';
                if (abs(s1[2]-s2[2]) == 2){
                    s+='1';
                    cout << s;
                    return 0;
                }
                else{
                    s+='0';
                    cout << s;
                    return 0;
                }
            }
            else{
                s+="00";
                cout << s;
                return 0;
            }
        }
        else{
            s+="000";
            cout << s;
            return 0;
        }
    }
    else{
        s+="0000";
        cout << s;
        return 0;
    }

    return 0;
}
