#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c1,c2;
    string s1,s2;
    bool f = 1;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else{
        cout << 0;
        f = 0;
    }
    if (s1[0] == s2[0] && s1[1] == s2[1] && f) cout << 1;
    else{
        cout << 0;
        f = 0;
    }
    bool state;
    if ((s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') && f){
            cout << 1;
            if (s1[2] <= 'C' && s2[2] <= 'C') state = 0;
            else state = 1;
    }
    else{
        cout << 0;
        f = 0;
    }
    if ((state == 0 && abs((int)s1[2] - (int)s2[2]) == 1 || state == 1 && abs((int)s1[2] - (int)s2[2]) == 2) && f) cout << 1;
    else cout << 0;
    return 0;
}
