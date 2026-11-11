#include <bits/stdc++.h>
using namespace std;
long long c[3] = {};
bool ans[5] = {};
string s[3] = {};

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c[1] >> s[1];
    cin >> c[2] >> s[2];

    if(c[1] == c[2]){
        ans[1] = 1;
        if(s[1][0] == s[2][0] && s[1][1] == s[2][1]){
            ans[2] = 1;
            if(s[1][2] > s[2][2]){
                swap(s[1], s[2]);
                swap(c[1], c[2]);
            }
            if((s[1][2] == 'A' && (s[2][2] == 'B' or s[2][2] == 'C')) or
               (s[1][2] == 'D' && s[2][2] == 'F')){
                ans[3] = 1;
                if((s[1][2] == 'A' && s[2][2] == 'B') or (s[1][2] == 'B' && s[2][2] == 'C') or (s[1][2] == 'D' && s[2][2] == 'F')){
                    ans[4] = 1;
                }
            }
        }
    }

    for(int i = 1;i <= 4;i++){
        cout << ans[i];
    }

    return 0;
}
