#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e6+10;
int a[N],tong[M];
int k[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	 } 
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i;j<=n;j++)
		{
			if(k[a[j]])
			{
				for(int l=k[a[j]];l<=j;l++)
				{
					k[a[l]]=0;
					
				}
				k[a[j]]=j;
			}
			else k[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(k[j])
				tong[j]++; 
		}
		memset(k,0,sizeof(k));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<" ";
	}
	
	
	return 0;
}
