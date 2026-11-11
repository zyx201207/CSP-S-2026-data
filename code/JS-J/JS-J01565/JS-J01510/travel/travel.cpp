#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cout<<1;
    else
        cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
        cout<<1;
    else
        cout<<0;
    char a=s1[2],b=s2[2];
    if(a>b)
        swap(a,b);
    if(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1]))
    {
        if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')||(a=='A'&&b=='C'))
            cout<<1;
        else
            cout<<0;
    }
    else
        cout<<0;
    if(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1]))
    {
        if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F'))
            cout<<1;
        else
            cout<<0;
    }
    else
        cout<<0;
    return 0;
}
