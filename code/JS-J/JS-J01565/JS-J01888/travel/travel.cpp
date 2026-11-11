#include <bits/stdc++.h>
using namespace std;
typedef int re;typedef long long ll;
inline bool gt(char a,char b){
    re zt1,zt2;
    if (a <= 'C' && a >= 'A') zt1 = 1;
    else if (a <= 'F' && a >= 'D') zt1 = 2;
    if (b <= 'C' && b >= 'A') zt2 = 1;
    else if (b <= 'F' && b >= 'D') zt2 = 2;
    return (zt1 == zt2);
}
inline bool pd(char a,char b){
    re zt3 = a - 'A',zt4 = b - 'A';
    if (zt3 == 5) zt3--;
    if (zt4 == 5) zt4--;
    return (abs(zt3 - zt4) == 1);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans = "0000";
    cin >> c1 >> s1 >> c2 >> s2;
    // part 1
    if (c1[0] == c2[0] && c1[1] == c2[1]) ans[0] = '1';
    // part 2
    if (ans[0] == '1' && s1[0] == s2[0] && s1[1] == s2[1]) ans[1] = '1';
    // part 3
    if (ans[1] == '1' && gt(s1[2],s2[2])) ans[2] = '1';
    // part 4
    if (ans[2] == '1' && pd(s1[2],s2[2])) ans[3] = '1';
    for (re i = 0;i < 4;i++) cout << ans[i];
    return 0;
}
