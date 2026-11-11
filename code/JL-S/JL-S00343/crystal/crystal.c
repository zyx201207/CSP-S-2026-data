#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","r",stdout);
long long a[12345],n,m,x=1,b[12345]=0,t[12345],d=0;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a[i];
}
sort(a+1,a+1+n)
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
if(a[i]==a[j])
b[i]++;
t[i]==a[i];
}
}
for(int s=1;s<=n;s++)
{
if(b[i])
{
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
if(b[i]<b[j])
{
swap(b[i],b[j]);
swap(t[i],t[j]);
}
}
}
d=b[1];
for(int i=1;i<=n;i++)
{
m=m-(a[i+1]+a[i]);
d++;
}
break;
}
else
if(m-(a[s+1]-a[s])*x!=0)
{
m=m-(a[i+1]-a[i])*x;
x++;
d++;
}
cout<<d;
}
return 0;
}
