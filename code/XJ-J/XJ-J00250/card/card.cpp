#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
long long n,m,a[N],b[N],c[N];
int main()
{

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=0;
		c[i]=0;
	} 
	long long r=1;
	for(int i=1;i<=n;i++)
	{
		if(b[a[i]]==0 && c[a[i]]==0)
		{
			for(int j=r;j<=i;j++)
			{
				b[a[j]]++;
				
			} 
			c[a[i]]=1;
		}
		else 
		{
			for(int j=r;j<=i-1;j++)
			{
				b[a[j]]++;
				c[a[j]]=0;
			} 
			r=i+1;
		}
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<b[i];
	} 
} 

