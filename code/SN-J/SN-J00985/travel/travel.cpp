#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!="01" && c1!="16"&&c2!="01" && c2!="16" &&c1==c2)
    {
        cout<<1;
        f1=1;
    }
    else
        cout<<0;
    if(s1[1]==s2[1] && s1[2]==s2[2])
    {
        cout<<1;
        f2=1;
    }
    else
        cout<<0;
    if(((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'))||((s1[3]=='D'||s2[3]=='F')&&(s2[3]=='D'||s1[3]=='F'))&&f1==1&&f2==1)
        cout<<1;
    else
        cout<<0;
    if((s1[3]-s2[3]==1||s1[3]-s2[3]==-1||(s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s2[3]=='D'))&&f1==1&&f2==1)
        cout<<1;
    else
        cout<<0;
    return 0;

}
