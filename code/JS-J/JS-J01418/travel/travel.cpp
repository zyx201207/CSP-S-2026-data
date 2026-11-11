#include<bits/stdc++.h>
using namespace std;
string a,b,n,num;
string x,y;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> x >> b >> y;
    if(a[0] == b[0] && a[1] == b[1])
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }


    if(x[0] == y[0] && x[1] == y[1])
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }


    if(x[3] == 'F' && y[3] == 'D')
    {
        cout << 11;
        return 0;
    }
    else if(x[3] == 'F' || x[3] == 'D' || y[3] == 'F' || y[3] == 'D')
    {

        cout << "00";
    }
    else if(!(x[3] == 'A' && y[3] == 'C'))
    {

        cout << 11;
    }
    else
    {
        cout << 10;
    }

    return 0;
}
