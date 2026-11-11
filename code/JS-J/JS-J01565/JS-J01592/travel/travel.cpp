#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool f1,f2,f3,f4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
    {
        f1=1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if((s2[0]==s4[0])&&(s2[1]==s4[1]))
    {
        f2=1;
    }
    else
    {
        cout<<"1000";
        return 0;
    }
    int x1=s2[2]-'A',x2=s4[2]-'A';
    if((x1<=2&&x2<=2)||(x1>=3&&x2>=3))
    {
        f3=1;
    }
    else
    {
        cout<<"1100";
        return 0;
    }
    if(abs(x1-x2)==1)
    {
        cout<<"1111";
        return 0;
    }
    else
    {
        cout<<"1110";
        return 0;
    }
    return 0;
}
