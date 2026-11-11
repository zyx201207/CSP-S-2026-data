#include <bits/stdc++.h>
using namespace std;
int c1, c2, a1, a2, b1, b2;
string s1, s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    a1 = (s1[0]-'0')*10 + s1[1]-'0';
    a2 = (s2[0]-'0')*10 + s2[1]-'0';
    b1 = s1[2]-'A'+1;
    b2 = s2[2]-'A'+1;
    if(c1 == c2){
        cout << 1;
        if(a1 == a2){
            cout << 1;
            if((b1<4 && b2 < 4) || (b1>3 && b2>3)){
                cout << 1;
                if(abs(b1-b2) == 1){
                    cout << 1 << endl;
                } else cout << 0 << endl;
            } else cout << "00" << endl;
        } else cout << "000" << endl;
    } else cout << "0000" << endl;
    return 0;
}
