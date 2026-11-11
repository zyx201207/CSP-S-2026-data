#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool a = (c1 == c2);
    bool b = a && (s1[1] == s2[1]);
    bool c = b && ((s1[2] >= 'D' && s2[2] >= 'D') || (s1[2] <= 'C' && s2[2] <= 'C'));
    bool d = c && (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1);
    cout << a << b << c << d;
    return 0;
}
