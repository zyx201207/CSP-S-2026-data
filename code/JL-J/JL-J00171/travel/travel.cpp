#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r1,r2,x1,x2;
    cin >> r1 >> r2 >> x1 >> x2;
    bool same_part = (r1 == x1);
    bool same_hang = (same_part && x2[0] == r2[0] && r2[1] == x2[1]);
    bool same_guodao = 0;
    if((r2[2] >= 'A' && r2[2] <= 'C') && (x2[2] != 'D' && x2[2] != 'F'))
    {
        same_guodao = 1;
    }
    else if((r2[2] == 'D' && x2[2] == 'F') || (x2[2] == 'D' && r2[2] == 'F'))
    {
        same_guodao = 1;
    }
    else{
        same_guodao = 0;
    }
    bool next_to = (same_guodao && (r2[2] == x2[2] + 1 || r2[2] == x2[2] - 1));
    cout << same_part << same_hang << same_guodao << next_to;
    return 0;
}
