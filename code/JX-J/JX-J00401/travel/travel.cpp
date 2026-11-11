#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, c2, s1, s2, ans;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == s1){
        ans = '1000';
    }
    else{
        ans = '0000';
    }
    if (c2[0] == s2[0] && c2[1] == s2[1]){
        ans[1] = '1';
        if (c2[2] == 'D' || c2[2] == 'F'){
            if (s2[2] == 'D' || s2[2] == 'F'){
                ans[2] = '1';
                ans[3] = '1';
            }
        }
        else{
            if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
                ans[2] = '1';
                if(c2[2] == 'A' && s2[2] == 'C'){
                    ans[3] = '0';
                }
                else if(c2[2] == 'C' && s2[2] == 'A'){
                    ans[3] = '0';
                }
                else{
                    ans[3] = '1';
                }
            }
        }
    }
    return 0;
}
