#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a=0;
    bool b=0;
    if(c1==c2)
    {
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
            {
                a=1;
            }
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
            {
                b=1;
            }
            if(a==b)
            {
                cout<<1;
            }else
            {
                cout<<0;
            }
            if((a==0&&b==0)||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C'))
            {
                cout<<1;
            }else
            {
                cout<<0;
            }

        }else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
