#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int s1_0 = s1[0] - '0', s1_1 = s1[1] - '0';
    int s2_0 = s2[0] - '0', s2_1 = s2[1] - '0';
    int s1s = s1_0 * 10 + s1_1, s2s = s2_0 * 10 + s2_1;
    if (c1 == c2){
        if (s1s == s2s){
            if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') || (s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')){
                if ((s1s+1 == s2s && s1[2]==s2[2]) || (s1s-1 == s2s && s1[2]==s2[2]) || (s1s==s2s && s1[2]+1==s2[2]) || (s1s==s2s && s1[2]-1==s2[2]) || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D'){
                        cout << "1111";
                }
                else cout << "1110";
            }
            else cout << "1100";
        }
        else cout << "1000";
    }
    else cout << "0000";
    return 0;
}
//30 min
//100 pts
