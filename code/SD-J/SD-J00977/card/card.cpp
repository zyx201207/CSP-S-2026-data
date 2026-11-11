#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int cnt[300005];
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			f=0;
	    }
	}
	if(n<=5000)
	{
		stack<int>s1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(cnt[a[j]])
				{
					while(s1.top()!=a[j])
					{
						cnt[s1.top()]--;
						s1.pop();
					}
				}
				else
				{
					cnt[a[j]]++;
					s1.push(a[j]);
				}
			}
			for(int i=1;i<=m;i++)
			{
				if(cnt[i])
				{
					ans[i]++;
				}
			}
			memset(cnt,0,sizeof(cnt));
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	if(f)
	{
		for(int i=1;i<=n;i++)
		{
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	if(m==2)
	{
		if(a[n]==1)
		{
			ans[1]=n;
			for(int i=1;i<n;i++)
			{
				if(a[i]==2)
				{
					ans[2]++;
				}
			}
		}
		if(a[n]==2)
		{
			ans[2]=n;
			for(int i=1;i<n;i++)
			{
				if(a[i]==1)
				{
					ans[1]++;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	return 0;
}
