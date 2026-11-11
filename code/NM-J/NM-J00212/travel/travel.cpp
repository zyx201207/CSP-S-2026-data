#include<bits/stdc++.h>
using namespace std;
int main()
{
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
            cout<<"0000";
    }
    else if(c1==c2)
    {
        if(s1[1]==s2[1] && s1[0]==s2[0])
        {
            if(s1[2]+1==s2[2] || s1[2]-1==s2[2])
            {
                if(s1[2]>'C' && s2[2]>'C')
                {
                    cout<<"1111";
                }
                else if(s1[2]<'D' && s2[2]<'D')
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1110";
                }
            }
            else
            {
                cout<<"1100";
            }
        }
        else
        {
            cout<<"1000";
        }
    }
    return 0;
}
