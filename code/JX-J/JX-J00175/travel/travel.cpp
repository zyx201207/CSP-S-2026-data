#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool a=1;
    cin >> c1 >> s1>> c2 >> s2;
    if(c1 == c2)
        cout << a;
    else{
        a = 0;
    for(int i= 1; i <= 4; i ++) {
        cout << a;}
        return 0;
        a=1;}
    if(s1[1] == s2[1]&&s1[0]==s2[0])
        cout << a;
    else{
        a = 0;
        cout << a;
        a=1;}
    if(s1[1] == s2[1]&&s1[0]==s2[0]&&abs(s1[2] - s2[2]) == 1 && (s1[2]<=67 && s2[2]<=67)||(s1[2]>67 && s2[2]>67))
        cout << a;
    else{
        a = 0;
        cout << a;
        a=1;}
    if(s1[1] == s2[1]&&s1[0]==s2[0]&&abs(s1[2] - s2[2]) == 1&& (s1[2]!=67 && s2[2] != 68)&&(s2[2]!=67 && s1[2] != 68))
        cout << a;
    else{
        a = 0;
        cout << a;
        a=1;}
    return 0;
}
