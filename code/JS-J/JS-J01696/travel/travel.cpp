#include <bits/stdc++.h>
using namespace std;
string x1;
string x2;
string w1;
string w2;
bool a,b,c;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x1>>x2;
    cin>>w1>>w2;
    a=(x1==w1);cout<<a;
    a=a&&(x2[0]*10+x2[1]==w2[0]*10+w2[1]);cout<<a;
    a=a&&((x2[2]<='C'&&w2[2]<='C')||((x2[2]>'C'&&w2[2]>'C')));cout<<a;
    a=a&&((x2[2]>'C'&&w2[2]>'C')||(x2[2]=='B')||(w2[2]=='B'));cout<<a;
    return 0;
}
