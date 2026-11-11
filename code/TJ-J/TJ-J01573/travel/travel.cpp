#include<bits/stdc++.h>
using namespace std;
struct seat
{
    string x;
    string y;
};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    seat n,m;
    cin >> n.x >> n.y >> m.x >> m.y;
    if(n.x[0] == m.x[0] && n.x[1] == m.x[1])
    {
        if(n.y[0] == m.y[0] && n.y[1] == m.y[1])
        {
            if(n.y[2] < 'D' && m.y[2] < 'D' || n.y[2] > 'C' && m.y[2] > 'C')
            {
                if(char(n.y[2])== char(m.y[2] + 1) || char(n.y[2]) == char(m.y[2] - 1))
                {
                    cout << "1111";
                }
                else{cout << "1110";}
            }
            else{cout << "1100";}
        }
        else{cout << "1000";}
    }
    else{cout << "0000";}
    return 0;
}
