#include<bits/stdc++.h>
using namespace std;

int main()
{

    freopen(trave.in,"r",stdin);
    freopen(trave.out,"w",stdout);

    char c1[2];
    char s1[3];
    char c2[2];
    char s2[3];
    for(int i=0;i<=1;i++)
    {
        cin>>c1;
    }
    for(int i=0;i<=2;i++)
    {
        cin>>s1;
    }
    for(int i=0;i<=1;i++)
    {
        cin>>c2;
    }
    for(int i=0;i<=2;i++)
    {
        cin>>s2;
    }
    if(c1[1]==c2[1])
        {
            cout<<'1';
        }
        else{
            cout<<'0';
        }

     if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<'1';
        }
        else{
            cout<<'0';
        }

        if(s1[2]=='A'||'B'||'C'&&s2[2]=='A'||'B'||'C'||s1[2]=='F'||'D'&&s2[2]=='F'||'D')
        {
           cout<<'1';
        }
        else{
            cout<<'0';
        }
    return 0;
}
