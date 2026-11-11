#include <bits/stdc++.h>
using namespace std;
string s1, s2, c1,c2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> s1 >> s2 >> c1 >> c2;
    if(s1 == c1){
        cout << "1";
        if(s2[0] == c2[0] && s2[1] == c2[1]){
            cout << "1";
            if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
                if(c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C'){
                    cout << "1";
                    if(abs(s2[2] - c2[2]) == 1){
                        cout << "1";
                    }
                    else{
                        cout << 0;
                    }
                }
                else{
                    cout << "00";
                }
            }
            else if(s2[2] == 'D' || s2[2] == 'F'){
                if(c2[2] == 'D' || c2[2] == 'F') {
                    cout << "11";
                }
                else{
                    cout << "00";
                }
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
