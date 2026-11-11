#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char x,r;
bool f = 1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2; x = s1[2],r = s2[2];
    if(x > r) swap(x,r);
    if(c1 != c2) cout << "0000";
    else{
        cout << "1";
        for(int i = 0;i < 2;i++) if(s1[i] != s2[i]) f = 0;
        if(f == 0) cout << "000";
        else{
            cout << "1";
            if(x == 'C' && r == 'D') cout << "00";
            else if(int(r) == int(x) + 1) cout << "11";
            else cout << "10";
        }
    }
    return 0;
}
