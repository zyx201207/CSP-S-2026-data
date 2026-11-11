#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x,x1,y,y1;
    cin >> x >> x1 >> y >> y1;
    if(x==y)
    {
        cout << "1";
        if(x1[0]==y1[0]&&x1[1]==y1[1])
        {
            cout << "1";
            if((x1[2]<=67 && y1[2]<=67)||(x1[2]>=68 && y1[2]>=68))
            {
                cout << "1";
                if (x1[2]+1==y1[2]||x1[2]-1==y1[2])
                {
                    cout << "1";
                }
                else
                {
                    cout << "0";
                }
            }
            else
            {
                cout << "00";
            }
        }
        else
        {
            cout << "000";
        }
    }
    else
    {
        cout << "0000";
    }
    return 0;
}
