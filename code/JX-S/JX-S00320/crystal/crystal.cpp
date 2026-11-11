#include<bits/stdc++.h>
using namespace std;
long long a[500000],p,x,y,ans,b[500000],sum,n,m;
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
int sum=0;
for(int i=1;i<=n;i++)
{
sum=a[i]+sum;}
x=sum/n;
for(int i=1;i<=n;i++)
{
if(a[i]>=x)b[i]=a[i]-x;
if(a[i]<x)b[i]=x-a[i];
}
sort(b,b+n);
for(int i=1;i<=n;i++)
{
m=m-b[i];
if(m>=0)ans++;
}
cout<<ans;
return 0;
}
