#include<bits/stdc++.h>
using namespace std;
int really[1000001]={};
int a[10000001]={};
int ji[1000001]={};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int ii=0;ii<=j;ii++)
			{
				if(a[ii]==a[j])
				{
					for(int jj=ii;jj<j;jj++)
					{
						really[jj]=1;
					}
				}
			}
			for(int b=0;b<n;b++)
			{
				if(really[b]!=1)
				{
					ji[really[b]]+=1;
				}
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<ji[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
