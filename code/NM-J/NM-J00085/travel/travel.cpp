#include <bits/stdc++.h>
using namespace std;
string s[105]={};
string c[105]={};
char s1[105]={};
char c1[105]={};
bool ss[105]={};
bool cc[105]={};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=1;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=3;i++)
    {
        cin>>s1[i];
        ss[i]=true;
    }
    for(int i=1;i<=1;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=3;i++)
    {
        cin>>c1[i];
        cc[i]=true;
    }
    if(s[1]==c[1]&&s[1]!="01"&&s[1]!="16")
    {
        cout<<"1";
        for(int i=1;i<=2;i++)
        {
            if(s1[i]!=c1[i])
            {
                ss[i]=false;
                cc[i]=false;
            }
        }
        for(int i=1;i<=2;i++)
        {
            if(ss[i]==false)
            {
                cout<<"000"<<endl;
                return 0;
            }
        }
        cout<<"1";
        if(s1[3]<='C'&&c1[3]<='C'||s1[3]>='D'&&c1[3]>='D')
        {
            cout<<"1";
        }
        else
        {
            cout<<"00";
            return 0;
        }
        if(s1[3]==c1[3]-1||s1[3]==c1[3+1])
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
            return 0;
        }
    }
    else
    {
        cout<<"0000"<<endl;
    }
    return 0;
}
