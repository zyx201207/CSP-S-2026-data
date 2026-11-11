#include<bits/stdc++.h>
using namespace std;
int n;
string c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        bool flag=true;
        for(int i=0;i<=1;i++)
        {
            if(s1[i]!=s2[i])
            {
                flag=false;
                break;
            }

        }
        if(flag)
        {
            cout<<1;
            if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))
            {
                cout<<1;
                if(s2[2]=='B')
                {
                    cout<<1;
                }
                else
                {

                    cout<<0;
                }
            }
            else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))
                cout<<"11";
            else if(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))
             {
                cout<<1;
                if(s2[2]=='B')
                {
                    cout<<1;
                }
                else
                {

                    cout<<0;
                }
            }
            else if(s1[2]=='D'&&s2[2]=='F')
                cout<<"11";
            else
                cout<<"00";
        }
        else
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
