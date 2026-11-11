#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
        cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    int a=s1[2]-'A',b=s2[2]-'A';
    if(0<=a&&a<=2&&0<=b&&b<=2||3<=a&&a<=4&&3<=b&&b<=4)
        cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }

    if(a-b==1||b-a==1)
        cout<<1;
    else
        cout<<0;
    return 0;
}
