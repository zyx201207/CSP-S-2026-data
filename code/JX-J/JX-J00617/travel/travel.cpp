#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,s,b,c;
    cin>>a>>s>>b>>c;
    if(a!=b)
    {
        cout<<"0000";
        return 0;
    }
    else if(a==b)
    {
        cout<<"1";
        if(s[0]==c[0]&&s[1]==c[1])
        {
            cout<<"1";
            if (s[2]-'@'<=3&&c[2]-'@'<=3)
            {
                cout<<"1";
                if(abs(s[2]-c[2])==1)
                {
                    cout<<"1";
                }
                else
                    cout<<"0";
            }
            else if(s[2]-'@'>3&&c[2]-'@'>3)
            {
                cout<<"11";
            }
            else
                cout<<"00";return 0;
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    return 0;
}
