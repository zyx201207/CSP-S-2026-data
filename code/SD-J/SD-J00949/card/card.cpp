#include<bits\stdc++.h> 
using namespace std;
long long a[2005],b[1000],t[1000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		bool ok[10000];
		memset(ok,1,sizeof(ok));
		for(int j=i;j<n;j++)
		{
			int bj=-1;
			for(int k=j;k>=0;k--)
			{
					if(a[j]==a[k]&&a[j]) bj=k;
			}
			if(bj!=-1)
			for(int o=bj;o<j;i++)
			{
				b[o]=0;
			}
		}
		for(int p=i;p<n;p++)
		{
			if(ok[p]) t[p]++;
		 } 
	}
	for(int i=1;i<m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
