#include<iostream>
#include<cmath>
using namespace std;
string c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else return cout<<"0000",0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else return cout<<"000",0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(
    (s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))
    {
        cout<<1;
        if(s1[2]<='C')
        {
            if(abs(s1[2]-s2[2])==1)cout<<1;
            else cout<<0;
        }
        else
        {
            cout<<1;
        }
    }
    else cout<<"00";
    return 0;
}
