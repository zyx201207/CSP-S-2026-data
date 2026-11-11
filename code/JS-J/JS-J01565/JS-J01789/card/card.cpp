#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005],stk[500005],top,f[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]])
			{
				while(stk[top]!=a[j]&&top)
				{
					f[stk[top]]--;
					top--;
				}
				stk[top]=a[j];
			}
			else
			{
				top++;
				stk[top]=a[j];
				f[a[j]]++;
			}
		}
		for(int j=1;j<=top;j++)
		{
			cnt[stk[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			f[j]=0;
		}
		top=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
