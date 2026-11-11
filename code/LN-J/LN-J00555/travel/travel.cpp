#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag1,flag2,flag3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
       cout << 1;
       flag1 = 1;
    }
    else cout << 0;
    if(flag1 && s1[0] == s2[0] && s1[1] == s2[1]){
        cout << 1;
        flag2 = 1;
    }
    else cout << 0;
    if(flag2 && ((s1[2]>='D' && s2[2] >= 'D') || (s1[2]<'D' && s2[2] < 'D'))){
        cout << 1;
        flag3 = 1;
    }
    else cout << 0;
    if(flag3 && abs(s1[2]-s2[2]) == 1) cout << 1;
    else cout << 0;
    return 0;
}
