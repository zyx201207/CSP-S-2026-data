#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int row1,row2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    row1=(s1[0]-'0')*10+s1[1]-'0';
    row2=(s2[0]-'0')*10+s2[1]-'0';
    if(row1!=row2)
    {
        cout<<"1000";
        return 0;
    }
    if(s1[2]=='F'||s1[2]=='D')
    {
        if(s2[2]!='F'&&s2[2]!='D')
        {
            cout<<"1100";
            return 0;
        }
        else
        {
            cout<<"1111";
            return 0;
        }
    }
    if(s2[2]=='F'||s2[2]=='D')
    {

        cout<<"1100";
        return 0;
    }
    cout<<"111";
    if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
    {
        cout<<"0";
        return 0;
    }
    cout<<"1";



    return 0;
}
