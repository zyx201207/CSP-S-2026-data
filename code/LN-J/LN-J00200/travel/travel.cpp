#include <bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main()
{
    feropen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> rc >> rs >> xc >> xs;
    if(rc==xc)
    {
        cout << 1;
        if(rs[0]==xs[0]&&rs[1]==xs[1])
        {
            cout << 1;
            if((rs[2]<=67&&xs[2]<=67)||(rs[2]=='D'&&xs=='F')||(rs[2]=='F'&&xs=='D'))
            {
                cout << 1;
                if(rs(2)==xs[2]+1||rs[2]==xs[2]-1||(rs[2]=='D'&&xs=='F')||(rs[2]=='F'&&xs=='D'))
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            else
            {
                cout << 0;
                cout << 0;
            }
        }
        else
        {
            cout << 0;
            cout << 0;
            cout << 0;
        }
    }
    else
    {
        cout << 0;
        cout << 0;
        cout << 0;
        cout << 0;
    }
    return 0;
}
