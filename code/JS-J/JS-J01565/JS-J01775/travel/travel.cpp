#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1, s1, c2, s2;
int f(string t){
    if(t[2]=='A'||t[2]=='B'||t[2]=='C') return 1;
    else return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1!=c2) cout << "0000";
    else{
        cout << 1;
        if(!(s1[0]==s2[0]&&s1[1]==s2[1])) cout << "000";
        else{
            cout << 1;
            if(f(s1)!=f(s2)) cout << "00";
            else{
                cout << 1;
                if(abs(s1[2]-s2[2])==1) cout << 1;
                else cout << 0;
            }
        }
    }
    return 0;
}
