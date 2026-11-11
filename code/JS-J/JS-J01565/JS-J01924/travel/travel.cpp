#include<bits/stdc++.h>
using namespace std;
int dxy[10] = {0, 1, 1, 1, 0, 0};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ax, bx, ay, by;
    cin >> ax >> bx >> ay >> by;
    int ix, jx, iy, jy;
    ix = (ax[0]-'0')*10+(ax[1]-'0');
    jx = (bx[0]-'0')*10+(bx[1]-'0');
    iy = (ay[0]-'0')*10+(ay[1]-'0');
    jy = (by[0]-'0')*10+(by[1]-'0');
    if(ix == iy && ix != 1 && ix != 16)
    {
        if(jx == jy)
        {
            if(dxy[bx[2]-'A'+1] == dxy[by[2]-'A'+1])
            {
                if(abs((bx[2]-'A'+1)-(by[2]-'A'+1)) == 1)
                {
                    cout << "1111";
                }
                else
                {
                    cout << "1110";
                }
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
