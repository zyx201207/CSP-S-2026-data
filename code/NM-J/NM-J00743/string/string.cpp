#include<bits/stdc++.h>
using namespace std;
string s,n;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int a=0,x,t=0,b=1,y=0;
cin>>a;
for(int i=1;i<=a;i=i+1)
{
    cin>>t>>s[b];
    for(int j=b+1;j<b+t;j++)
        s[j]=s[b];
    b=b+t;
}
for(int i=s.size();i>=1;i--)
    n[i]=s[i];
for(int i=1;i<=s.size();i++)
{
    if(n[i]!=s[i])
        y++;
}
cout<<y;
return 0;
}
