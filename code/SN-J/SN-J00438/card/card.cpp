#include<bits/stdc++.h>
using namespace std;
int q[10000],ans[10000000];
int a[10000000],k[12000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=n;
	while(x>0)
	{
		int top=0;
		for(int i=1;i<=n;i++)
		{
			if(k[a[i]]==1)
			{
				while(q[top]!=a[i])
				{
					q[top]=0;
					top--;
				}
				q[top]=0;
				top--;
			}
			q[top++]=a[i];
			k[a[i]]++;
		}
		for(int i=1;i<=top;i++)
		{
			ans[q[i]]++;
			q[i]=0;
		}
		x--;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
