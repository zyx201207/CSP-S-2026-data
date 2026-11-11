#include<bits/stdc++.h>
using namespace std;
char c1[10], s1[10], c2[10], s2[10], ans[5];
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
    if(c1[1] == c2[1] && c1[2] == c2[2]) ans[1] = '1';
    else ans[1] = '0';
    if(ans[1] == '1' && s1[1] == s2[1] && s1[2] == s2[2]) ans[2] = '1';
    else ans[2] = '0';
    if(ans[1] == '1' && ans[2] == '1' && (s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C')){
        if(s2[3] == 'A' || s2[3] == 'B' || s2[3] == 'C'){
            ans[3] = '1';
        }
        else ans[3] = '0';
        if(ans[1] == '1' && ans[2] == '1' && ans[3] == '1'){
            if(s1[3] == 'A' && s2[3] == 'B'){
                ans[4] = '1';
            }
            else if(s1[3] == 'B' && s2[3] == 'A'){
                ans[4] = '1';
            }
            else if(s1[3] == 'C' && s2[3] == 'B'){
                ans[4] = '1';
            }
            else if(s1[3] == 'B' && s2[3] == 'C'){
                ans[4] = '1';
            }
            else ans[4] = '0';
        }
        else ans[4] = '0';
    }
    else if(ans[1] == '1' && ans[2] == '1' && (s1[3] == 'D' || s1[3] == 'F')){
        if(s2[3] == 'D' || s2[3] == 'F'){
            ans[3] = '1';
        }
        else ans[3] = '0';
        if(ans[1] == '1' && ans[2] == '1' && ans[3] == '1'){
            if(s1[3] == 'D' && s2[3] == 'F'){
                ans[4] = '1';
            }
            else if(s2[3] == 'F' && s2[3] == 'D'){
                ans[4] = '1';
            }
            else ans[4] = '0';
        }
        else ans[4] = '0';
    }
    else ans[3] = '0', ans[4] = '0';
    for(int i = 1; i <= 4; i++){
        printf("%c", ans[i]);
    }
    return 0;
}
