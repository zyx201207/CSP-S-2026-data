#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool flag1 = 1, flag2 = 1, flag3 = 1, flag4 = 1;
    for(int i = 0; i < c1.length(); i++){
        if(c1[i] != c2[i]){
            flag1 = 0;
            flag2 = 0;
            flag3 = 0;
            break;
        }
    }
    for(int i = 0; i < 2; i++){
        if(s1[i] != s2[i]){
            flag2 = 0;
            flag3 = 0;
            break;
        }
    }
    if((s1[2] <= 'C' && s2[2] > 'C') || (s2[2] <= 'C' && s1[2] > 'C')){
        flag3 = 0;
    }
    if(!flag1 || !flag2 || !flag3 || !((abs(s1[2] - s2[2]) == 1) || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' || s2[2] == 'D'))){
        flag4 = 0;
    }
    cout << flag1 << flag2 << flag3 << flag4;
    return 0;
}
