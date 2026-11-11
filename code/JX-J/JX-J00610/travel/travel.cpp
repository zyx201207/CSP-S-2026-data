#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,x1,c2,x2;
    cin>>c1>>x1>>c2>>x2;
    if(c1==c2)
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }
    string a=x1;
    a+=x1[1];
    string b=x2;

    if(a[0]==b[0] && a[1]==b[1])
    {
        cout << 1;
        if((x1[2]>='A' && x1[2]<='C' && x2[2]>='A' && x2[2]<='C') || (x1[2]>='D' && x1[2]<='F' && x2[2]>='D' && x2[2]<='F'))
        {
            cout << 1;
            if(abs((int)(x1[2]-x2[2]))==1)
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
            cout << "00";
        }
    }
    else
    {

        cout << "000";
    }

    return 0;
}
