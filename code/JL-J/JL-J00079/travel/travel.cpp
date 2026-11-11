#include<bits/stdc++.h>
using namespace std;
string c;
string s;
string c2;
string s2;
string ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>c2>>s2;
    if(c==c2)
    {
        ans=ans+"1";
        if(s[0]+s[1]==s2[0]+s2[1])
        {
            ans=ans+"1";
        }
        else{
            ans=ans+"0";
            ans=ans+"0";
        }
        if(s[0]+s[1]==s2[0]+s2[1])
        {
            if(s[2]>'C')
            {
                if(s2[2]>'C')
                {
                    ans=ans+"1";
                }
            }
        if(s[2]<='C'&&s2[2]<='C')
        {
            ans=ans+"1";
        }

        if(s[2]<='C'&&s2[2]>'C')
        {
            ans=ans+"0";
            ans=ans+"0";
        }
        if(s[2]>'C'&&s2[2]<='C')
        {
            ans=ans+"0";
            ans=ans+"0";
        }
        if(s2[2]<='C'&&s[2]<='C')
        {
            if(s[2]!='B'&&s2[2]!='B')
            {
                ans=ans+"0";
            }
            else{
                ans=ans+"1";
            }
        }

    }

    }
    else{
            ans=ans+"0";
            ans=ans+"0";
            ans=ans+"0";
            ans=ans+"0";
        }
    cout<<ans;
    return 0;
}
