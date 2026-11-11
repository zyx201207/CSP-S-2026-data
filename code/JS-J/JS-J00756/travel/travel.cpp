#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
string s1, s2, s3, s4;
char pos[200];
signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s1 >> s2 >> s3 >> s4;
    pos['A'] = 'A', pos['B'] = 'B', pos['C'] = 'C';
    pos['D'] = 'H', pos['F'] = 'I';
    s2[2] = pos[s2[2]];
    s4[2] = pos[s4[2]];
    if(s1 == s3){
        cout << "1";
        if(s2[0] == s4[0] && s2[1] == s4[1]){
            cout << "1";
            if(abs(s2[2] - s4[2]) <= 2){
                cout << "1";
                if(abs(s2[2] - s4[2]) == 1){
                    cout << "1";
                }
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else{
        cout << "0000";
    }
    return 0;
}
