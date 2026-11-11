#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
    if(s1.size()-s2.size()<=1)
    {
        cout<<"1";
    }
    else
    {
       cout<<"0";
    }
    if(c2==c1)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if(s2.size()-s1.size()<=1)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
