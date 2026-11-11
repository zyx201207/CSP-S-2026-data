#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    char a1 = s1[0],a2 = s2[0];
    char b1 = s1[1],b2 = s2[1];
    char w1 = s1[2],w2 = s2[2];
    if (c1 == c2){
        cout << 1;
        if (a1 == a2 && b1 == b2){
            cout << 1;
            if ((w1 >= 'A' && w2 <= 'C') || (w1 >= 'D' && w2 <= 'F')){
                cout << 1;
                if (abs(w1 - w2) == 1){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                cout << "00";
                return 0;
            }
        }else{
            cout << "000";
            return 0;
        }
    }else{
        cout << "0000";
        return 0;
    }
    return 0;
}
