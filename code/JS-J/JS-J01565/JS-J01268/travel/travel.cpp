#include <bits/stdc++.h>
using namespace std;
char c1[5],s1[5],s2[5],c2[5];

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++) cin>>c1[i];
    for(int i=1;i<=3;i++) cin>>s1[i];
    for(int i=1;i<=2;i++) cin>>c2[i];
    for(int i=1;i<=3;i++) cin>>s2[i];

    for(int i=1;i<=2;i++)
    {
        if(c1[i]!=c2[i])
        {
             cout<<"0000";
            return 0;
        }
    }
    cout<<1;

    for(int i=1;i<=2;i++)
    {
        if(s1[i]!=s2[i])
        {
             cout<<"000";
            return 0;
        }
    }
    cout<<1;


    if(s1[3]=='A'&&s2[3]=='B') cout<<1;
    else if(s1[3]=='A'&&s2[3]=='C') cout<<1;
    else if(s1[3]=='B'&&s2[3]=='A') cout<<1;
    else if(s1[3]=='B'&&s2[3]=='C') cout<<1;
    else if(s1[3]=='C'&&s2[3]=='B') cout<<1;
    else if(s1[3]=='C'&&s2[3]=='A') cout<<1;
    else if(s1[3]=='D'&&s2[3]=='F') cout<<1;
    else if(s1[3]=='F'&&s2[3]=='D') cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }


    if(s1[3]=='A'&&s2[3]=='B')
    {
         cout<<1;
        return 0;
    }
    else if(s1[3]=='B'&&(s2[3]=='A'||'C'))

    {
        cout<<1;
        return 0;

    }
    else if(s1[3]=='C'&&s2[3]=='B')
    {
        cout<<1;
        return 0;
    }
    else if(s1[3]=='D'&&s2[3]=='F')
    {

        cout<<1;
        return 0;
    }
    else if(s1[3]=='F'&&s2[3]=='D')
    {
        cout<<1;
        return 0;
    }
    else cout<<0;
    return 0;
}
