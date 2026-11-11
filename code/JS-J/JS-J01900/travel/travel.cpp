#include<bits/stdc++.h>
using namespace std;
bool panduan(char a,char b)
{
    int x1=a-'A';
    int x2=b-'A';
    int mx=max(x1,x2);
    int mn=min(x1,x2);
    if(mx==5&&mn==3) return 1;
    if(mx-mn!=1) return 0;
    if(mx==3&&mn==2) return 0;
    else return 1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        cout<<1;
       if(s2[0]==s4[0]&&s2[1]==s4[1])
       {
           cout<<1;
            if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C') cout<<1;
            else if(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F') cout<<1;
            else cout<<0;
           if(panduan(s2[2],s4[2])) cout<<1;
           else cout<<0;
       }
       else
       {
           cout<<0<<0<<0;
       }
    }
    return 0;
}
