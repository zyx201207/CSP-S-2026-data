#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string c1,s1,c2,s2,ans="";
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2) {
        ans+="1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]) {
            ans+="111";
        }
        else {
            ans+="000";
        }
    }
    else {
        cout << "0000";
    }
    cout << ans;
    return 0;
}
