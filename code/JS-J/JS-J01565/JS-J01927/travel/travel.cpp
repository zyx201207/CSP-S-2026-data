#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int ans1,ans2,ans3,ans4;
int str_to_int(string c1) {
    return (c1[0]-'0')*10 + (c1[1]-'0');
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (str_to_int(c1) == str_to_int(c2) && str_to_int(c1) != 1 && str_to_int(c1) != 16 && str_to_int(c2) != 1 && str_to_int(c2) != 16){
        ans1 = 1;
    }
    int pai1 = str_to_int(s1),pai2 = str_to_int(s2);
    if (ans1 && pai1==pai2) ans2=1;
    if ((('A'<=s1[2] && s1[2] <= 'C' && 'A'<=s2[2] && s2[2] <= 'C') || ('D'<=s1[2] && s1[2] <= 'F' && 'D'<=s2[2] && s2[2] <= 'F')) && ans2){
        ans3 =1;
    }
    if (ans3 && (((s1[2]-s2[2]) == 1 || s1[2]-s2[2] == -1) && !((s1[2] == 'D' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'D')))){
        ans4 =1;
    }
    cout << ans1 << ans2 << ans3 << ans4 << endl;
    return 0;
}