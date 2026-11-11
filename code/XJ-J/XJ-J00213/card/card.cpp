#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
int main()
{
freopen("card.in","w",stdin);
freopen("card.out","r",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a[i];
	a[i]<n;

for(int k=1;k<=n;k++)
{
		
if(a[i]==a[i+n])
{
	erase(k+1,i+n-1);
}
if(a[i]=k)
{
	cnt++;
}
}
cout<<cnt;


return 0;
}
