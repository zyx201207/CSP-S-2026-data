#include<bits/stdc++.h>
using namespace std;
long long a[500100],ji[500100],v[500100],d=1,q[500100];
int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i;j<=n;j++)
		{
			if(ji[a[j]]!=0)
			{
				for(int k=v[j];k<=j-1;k++)
				{
					ji[a[k]]=0;
				}
				v[a[j]]=j;
			}
			else{
				v[a[j]]=j;
				ji[a[j]]++;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(ji[j]!=0)
			{
				q[i]++;
			}
			ji[j]=0;
			v[j]=0;
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<q[i];
	}
	
	return 0;
} 
