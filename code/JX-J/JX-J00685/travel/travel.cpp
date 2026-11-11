#include <bits/stdc++.h>
using namespace std;
char e[3];
int fe(char a,char b)
{
    int aa = 0,bb = 0;
    for(int i = 0;i <= 3;i++)
    {
        if(a == e[i])
        {
            aa = 1;
        }
        if(b == e[i])
        {
            bb = 1;
        }
    }
    if (aa==bb)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    e[0] = 'A';
    e[1] = 'B';
    e[2] = 'C';
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == c)
    {
        cout << "1";
        if((b[0] == d[0])&&(b[1] == d[1]))
        {
            cout << "1";
            if(fe(b[2],d[2]))
            {
                cout << "1";
                if(abs(b[2]-d[2]) == 1)
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
