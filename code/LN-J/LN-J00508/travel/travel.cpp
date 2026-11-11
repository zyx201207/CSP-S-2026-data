#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s3[i])
        {
            cout<<0000;
            return 0;
        }
    }
    cout<<1;
    if(s2[0]==s4[0]&&s2[1]==s4[1])
    {
        cout<<1;
        if((s2[2]-'A'<=2&&s4[2]-'A'<=2)||(s2[2]-'A'>2&&s4[2]-'A'>2))
        {
            cout<<1;
            if(abs((s2[2]-'A')-(s4[2]-'A'))==1) cout<<1;
            else cout<<0;
        }
        else cout<<00;
    }
    else
    {
        cout<<000;
    }
    return 0;
}
