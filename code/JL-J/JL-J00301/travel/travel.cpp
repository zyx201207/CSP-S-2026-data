#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
    freopen("trevel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool f=false,fa=false;
    if(c1!=c2)
    {
        cout<<0<<0<<0;
        for(char i='A';i<='F';i++)
        {
            char t=i;
            if(s1[2]==t&&s2[2]==(char)t+1)
            {
                if(s1[2]!='C'&&s2[2]!='D'||s1[2]!='D'&&s2[2]!='C')
                {
                    f=true;
                    break;
                }
            }
        }
        if(f)cout<<1;
        else cout<<0;
    }
    else
    {
        cout<<1;
        if(s1[1]==s2[1])
        {
            cout<<1;
            for(char i='A';i<='F';i++)
            {
                char t=i;
                if(s1[2]=t&&s2[2]==(char)t+1)
                {
                    f=true;
                    if(s1[2]!='C'&&s2[2]!='D'||s2[2]!='C'&&s1[2]!='D')
                    {
                        fa=true;
                        break;
                    }

                }
            }
            if(f&&fa)cout<<1<<1;
            else if(f) cout<<1<<0;
            else cout<<0<<0;
        }

        else cout<<0<<0;
    }
    return 0;
}
