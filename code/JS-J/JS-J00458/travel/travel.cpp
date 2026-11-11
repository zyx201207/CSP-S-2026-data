#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ac,bc;
string a,b,as,bs;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> as >> b >> bs;
    if (a == b)
    {
        if (as[0] == bs[0] && as[1] == bs[1])
        {
            ac = as[2] - 'A';
            bc = bs[2] - 'A';
            if (ac <= 2 && bc <= 2)
            {
                if (abs(ac-bc) == 1)
                {
                    cout << "1111";
                }
                else
                {
                    cout << "1110";
                }
            }
            else if (ac >= 3 && bc >= 3)
            {
                cout << "1111";
            }
            else
            {
                cout << "1100";
            }
        }
        else
        {
            cout << "1000";
        }
    }
    else
    {
        cout << "0000";
    }
    return 0;
}
