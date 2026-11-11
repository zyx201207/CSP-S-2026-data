#include<bits/stdc++.h>
using namespace std;

string c1 = "", c2 = "", s1 = "", s2 = "";

int main(){
    string ans1 = "0", ans2 = "0", ans3 = "0", ans4 = "0";
    cin >> c1 >> s1 >> c2 >> s2;
    int C1 = int(c1[0]) * 10 + int(c1[1]);
    int C2 = int(c2[0]) * 10 + int(c2[1]);
    int L1 = int(s1[0]) * 10 + int(s1[1]);
    int L2 = int(s2[0]) * 10 + int(s2[1]);
    char R1 = s1[2];
    char R2 = s2[2];
    if(C1 == C2){
        ans1 = "1";
        if(L1 == L2){
            ans2 = "1";
            if((R1 <= 'C' && R2 <= 'C') || (R1 > 'C' && R2 > 'C')){
                ans3 = "1";
                if(R1 - R2 == 1 || R1 - R2 == -1){
                    ans4 = "1";
                }
            }
        }
    }
    string ans = ans1 + ans2 + ans3 + ans4;
    cout << ans;
    return 0;
}
