#include<bits/stdc++.h>
using namespace std;
char a1[5],a2[5],b1[5],b2[5];
int a,b,n,m;
int main(){
freopen<"travel.in","r",stdin>;
freout<"travel.out","w",stdout>;
cin>>a1[1]>>a1[2]>>a2[1]>>a2[2]>>a2[3]>>b1[1]>>b1[2]>>b2[1]>>b2[2]>>b2[3];
a=(a1[1]-'0')*10+a1[2]-'0';
b=(a2[1]-'0')*10+a2[2]-'0';
n=(b1[1]-'0')*10+b1[2]-'0';
m=(b2[1]-'0')*10+b2[2]-'0';
if(a==n)
{
    cout<<1;
    if(b==m)
    {
        cout<<1;
        if(a2[3]=='D'&&b2[3]=='F'||b2[3]=='D'&&a2[3]=='F')
        {
            cout<<11;
        }
        else if(a2[3]!='D'&&a2[3]!='F'&&b2[3]!='D'&&b2[3]!='F')
        {
            cout<<1;
            if(a2[3]+1==b2[3]||a2[3]-1==b2[3])
            {
                cout<<1;
            }
            else
            {
            cout<<"0";
            }
        }
        else
        {
            cout<<"00";
        }
    }
    else
    {
        cout<<"000";
    }
}
else
{
    cout<<"0000";
}
return 0;
}
