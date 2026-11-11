#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int work(char a)
{
    if(a=='A' || a=='B' || a=='C')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
    }
    else
    {
        cout<<'1';
        if(s1[0]!=s2[0] || s1[1]!=s2[1])
        {
            cout<<"000";
        }
        else
        {
            cout<<'1';
            if(work(s1[2])!=work(s2[2]))
            {
                cout<<"00";
            }
            else
            {
                cout<<'1';
                if(work(s1[2])==2)
                {
                    cout<<'1';
                }
                else
                {
                    if((s1[2]=='A' && s2[2]=='C')||(s1[2]=='C' && s2[2]=='A'))
                    {
                        cout<<'0';
                    }
                    else
                    {
                        cout<<'1';
                    }
                }
            }
        }
    }
    return 0;
}
