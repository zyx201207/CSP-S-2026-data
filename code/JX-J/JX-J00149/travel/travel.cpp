#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag=false;
void paishu()
{
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
}
void side()
{
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
          {
              flag=true;
              cout<<1;
          }
        else if((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D'))
          {
              flag=true;
              cout<<1;
          }
        else
            cout<<0;
    }
    else
        cout<<0;
}
void next()
{
    if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')&&flag)
        cout<<1;
    else if((s1[2]=='C'&&s2[2]=='B')||(s2[2]=='B'&&s1[2]=='C')&&flag)
        cout<<1;
    else if((s1[2]=='F'&&s2[2]=='D')||(s2[2]=='D'&&s1[2]=='F')&&flag)
        cout<<1;
    else
        cout<<0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    if(c1!=c2){
        cout<<0;
    }            //chexiang
    paishu();
    side();
    next();
    return 0;
}
