#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,a[1000000],t=0;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
if(m==1)
{
for(int i=1;i<=n;i++)
{
t=max(a[i],t);
}
}
if(m==n)
{
t=a[1];
for(int i=2;i<=n;i++)
{
t=t&a[i];
}
}
cout<<t;
return 0;
}
