#include <bits/stdc++.h>
using namespace std;
char a[15],b[15],c[15],d[15];
int n[15];
int main ()
{
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    cin >>a[1]>>a[2];
    cin >>b[1]>>b[2]>>b[3];
    cin >>c[1]>>c[2];
    cin >>d[1]>>d[2]>>d[3];
    if (a[1]==c[1] && a[2]==c[2])
    {
        n[1]=1;
    }
    else
    {
        cout <<"0000";
        return 0;
    }
    if (b[1]==d[1] && b[2]==d[2])
    {
        n[2]=1;
    }
    else
    {
        cout <<"1000";
        return 0;
    }
    if ((b[3]=='A'&&d[3]=='B')||(b[3]=='A'&&d[3]=='C')||(b[3]=='B'&&d[3]=='A')||(b[3]=='B'&&d[3]=='C')||(b[3]=='C'&&d[3]=='B')||(b[3]=='C'&&d[3]=='A')||(b[3]=='D'&&d[3]=='F')||(b[3]=='F'&&d[3]=='D'))
    {
        n[3]=1;
    }
    else
    {
        cout <<"1100";
        return 0;
    }
    if ((b[3]=='A'&&d[3]=='B')||(b[3]=='B'&&d[3]=='C')||(b[3]=='B'&&d[3]=='A')||(b[3]=='C'&&d[3]=='B')||(b[3]=='D'&&d[3]=='F')||(b[3]=='F'&&d[3]=='D'))
        n[4]=1;
    cout <<n[1]<<n[2]<<n[3]<<n[4]<<endl;
    return 0;
}
