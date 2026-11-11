#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a>> b>> c>> d;
    if(a==c)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(a==c&&b[0]==d[0]&&b[1]==d[1])
    {
        cout << 1;
    }
    else
    {
    cout << 0;
    }
    if(a==c&&b[0]==d[0]&&b[1]==d[1])
    {
        if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
        {
            cout << 1;
        }
        else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
        {
            cout<<1;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }
    if(a==c&&b[0]==d[0]&&b[1]==d[1])
    {
        if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
        {
            int f=int(b[2]);
            int g=int(d[2]);
            if(abs(f-g)==1)
            {
                cout <<1;
            }
            else
            {
                cout <<0;
            }
        }
        else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
        {
            cout<<1;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }
    return 0;
}
