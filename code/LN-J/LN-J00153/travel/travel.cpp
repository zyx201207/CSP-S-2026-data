#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n,m,nc,mc;
    cin >> n >> nc >> m >> mc;
    if (n != m) cout << "0000";
    else if (nc[0] != mc[0] || nc[1] != mc[1]) cout << "1000";
    else if (nc[2] == 'A' && (mc[2]!='B' && mc[2] != 'C')) cout << "1100";
    else if (nc[2] == 'B' && (mc[2]!='A' && mc[2] != 'C')) cout << "1100";
    else if (nc[2] == 'C' && (mc[2]!='A' && mc[2] != 'B')) cout << "1100";
    else if (nc[2] == 'D' && mc[2]!='F') cout << "1100";
    else if (nc[2] == 'F' && mc[2]!='D') cout << "1100";
    else if (nc[2] == 'A' && mc[2]!='B') cout << "1110";
    else if (nc[2] == 'B' && (mc[2]!='A' && mc[2] !='C')) cout << "1110";
    else if (nc[2] == 'C' && mc[2]!='B') cout << "1110";
    else if (nc[2] == 'D' && mc[2]!='F') cout << "1110";
    else if (nc[2] == 'F' && mc[2]!='D') cout << "1110";
    else cout << "1111";
    return 0;
}
