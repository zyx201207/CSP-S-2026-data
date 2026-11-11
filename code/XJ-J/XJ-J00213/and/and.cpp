#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,p;
int a[1000000];
int b[1000000];
int c[1000000];
int q[1000000];
int main()
{
freopen("and.in","w",stdin);
freopen("and.out","r",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a[i];	
}
for(int i=1;i<=n;i++)
{	
a[i]%2=b[i];
a[i]/2=a[i+1];
}
if(a[i]==b[i])
{
	c[i]=1;
}
for(int v=1;v<=i;v++)
{
c[i]*2*i=q[i];	
q[i]=m;
if(q[i+1]>q[i])
{
	q[i+1]=m;
}
}
cout<<m;
return 0;
}
