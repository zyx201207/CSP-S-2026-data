#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c >> d;
    if(a!=c) cout << "0000";
    else
    {
        cout << '1';
        if(b[0]!=d[0]||b[1]!=d[1]) cout << "000";
        else
        {
            cout << '1';
            if((b[2]=='D'||b[2]=='F')^(d[2]=='D'||d[2]=='F')) cout << "00";
            else cout << '1' << (abs(d[2]-b[2])==1);
        }
    }
    return 0;
}
