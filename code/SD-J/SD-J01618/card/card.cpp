#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n>5e3)
	{
	int sum[m+10]={};
	int a[n+10];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int d[m+10]={};
		stack<int>stk;
		for(int j=i;j<=n;j++)
		{
			if(d[a[j]]==1) {
				while(stk.top()!=a[j])
				{
					d[stk.top()]=0;
					stk.pop();
				}
			}
			else {
				stk.push(a[j]);
				d[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			sum[j]+=d[j];
		}
	}
	for(int j=1;j<=m;j++)
	{
		printf("%d ",&sum[j]);
	}
	}
	else
	{
	int sum[m+10]={};
	int a[n+10];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int d[m+10]={};
		stack<int>stk;
		for(int j=i;j<=n;j++)
		{
			if(!d[a[j]]){
				stk.push(a[j]);
				d[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			sum[j]+=d[j];
		}
	}
	for(int j=1;j<=m;j++)
	{
		printf("%d ",&sum[j]);
	}	
	}
	return 0;
}

