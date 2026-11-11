#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool c,l,h;
    if(c1==c2)
    {
        cout<<1;
        c=1;

    }
    else{
        cout<<0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<1;
        l=1;

    }
    else{
        cout<<0;
    }
    if(s1[2]<='C'&&s2[2]>='D'||s1[2]>='D'&&s2[2]<='C')
    {
        cout<<0;

    }
    else{
        cout<<1;
        h=1;
    }
    if(c==1&&l==1&&h==1)
    {
        if(s1[2]-'A'==s2[2]-'A'-1||s1[2]-'A'==s2[2]-'A'+1)
        {
                    cout<<1;

        }
        else{
                cout<<0;
        }


    }
    else{
        cout<<0;
    }
    return 0;
}
