#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,cs1,cs2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    s1=' '+s1;
    s2=' '+s2;
    cs1=s1[1]+s1[2];
    cs2=s2[1]+s2[2];
    if(c1!=c2)
    {
        cout<<"0000";
    }
    else
    {
        if(cs1!=cs2)
        {
            cout<<"1000";
        }
        else if(s1[3]=='D'||s1[3]=='F')
        {
            if(s2[3]=='D'||s2[3]=='F')
            {
                cout<<"1111";
            }
            else
            {
                cout<<"1100";
            }
        }
        else
        {
            if(s2[3]!='A'&&s2[3]!='B'&&s2[3]!='C')
            {
                cout<<"1100";
            }
            else
            {
                if(s1[3]=='B')
                {
                    cout<<"1111";
                }
                else
                {
                    if(s2[3]=='B')
                    {
                        cout<<"1111";
                    }
                    else
                    {
                        cout<<"1110";
                    }
                }
            }
        }
    }
    return 0;
}
