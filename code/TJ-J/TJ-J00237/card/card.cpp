#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen(card.in,"r",stdin);
	freopen(card.out,"w",stdin);
int n,m;
cin>>n>>m;
int a[500001];
int b[500001];
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
for(int i=0;i<n;i++)
{
	if(i==0)
	continue;
	for(int j=1;j<=n;j++)
	{
	if(a[j]=a[i])
	{
		a[i]=0;
		a[j]=0;
		}	
	}
}
for(int i=0;i<m;i++)
{
	for(int j=1;i<=j;i++)
	{
		if(a[i]==i)
		{
			b[i]+1;
		}
	}
}
for(int i=1;i<=m;i++)
{
	cout<<b[i]<<" ";
}
return 0;
 } 
