#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int r=0,l=0;
    cin >> a >> b >> c >> d;
    if(a==c)
        cout << "1";
    else
    {
        cout << "0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1])
        cout << "1";
    else
    {
        cout << "000";
        return 0;
    }
    if(b[2]==65||b[2]==66||b[2]==67)
        l+=1;
    else
        r+=1;
    if(d[2]==65||d[2]==66||d[2]==67)
        l+=1;
    else
        r+=1;
    if(l==2||r==2)
        cout << "1";
    else
    {
        cout << "00";
        return 0;
    }
    if(r==2)
        cout << "1";
    else if(b[2]==d[2]+1||b[2]+1==d[2])
        cout << "1";
    else
        cout << "0";
    return 0;
}
