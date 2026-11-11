#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
string s;
char b;
long long n,a[12345],x=0,t=0;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>a[i]>>b;
s[i]=b;
}
for(int i=0;i<s.size();i++)
{
if(s[i]!=s[n-i])
{
t++;
}
}
if(t==0)
{
cout<<x;
}
else
cout<<t/2;
return 0;
}
