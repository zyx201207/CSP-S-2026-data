#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    char a=s1[0],b=s1[1],c=s2[0],d=s2[1];
    if(a==c&&b==d)cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    char x=s1[2],y=s2[2];
    if(x+1==y||x-1==y||(x=='D'&&y=='F')||(x=='F'&&y=='D'))cout<<1;
    else cout<<0;
    return 0;
}
