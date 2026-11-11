#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int side[10]={1,1,1,2,2};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1.substr(0,2)==s2.substr(0,2))
        cout<<"1";
    else
    {
        cout<<"000";
        return 0;
    }
    int x1=s1[2]-'A',x2=s2[2]-'A';
    if(x1==5)
        x1=4;
    if(x2==5)
        x2=4;
    if(side[x1]==side[x2])
        cout<<"1";
    else
    {
        cout<<"00";
        return 0;
    }
    if(abs(x1-x2)==1)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}
