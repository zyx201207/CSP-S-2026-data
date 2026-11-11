#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int line,row,line2,row2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    line=(b[0]-'0')*10+b[1]-'0';
    line2=(d[0]-'0')*10+d[1]-'0';
    //row=b[2]-"A";
    //row2=d[2]-"A";
    if(a!=c) cout << "0000";
    else if(line!=line2) cout << "1000";
    else if(((b[2]>='A' && b[2]<='C') && (d[2]=='D' || d[2]=='F')) || ((d[2]>='A' && d[2]<='C') && (b[2]=='D' || b[2]=='F')))cout << "1100";
    else if(abs(b[2]-d[2])==1 || (b[2]=='F' && d[2]=='D') || (d[2]=='F' && b[2]=='D')) cout << "1111";
    else cout << "1110";
    return 0;
}
