#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005]={0};
int ans;
int maxx;
int dfs(int sum,int id,int k)
{
	if(id==n+1)
	{
		return 0;
	}
	else if(k==m)
	{
		return sum;
	}
	else
	{
		int num;
		if(sum==0)
		{
			num=a[id];
		}
		else
		{
			num=sum&a[id];
		}
		return max(dfs(num,id+1,k+1),dfs(sum,id+1,k));
	}
}
bool cmp(int x1,int x2)
{
	return x1>x2;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	ans=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(a[i],maxx);
		ans&=a[i];
	}
	if(m==n)
	{
		cout<<ans<<endl;
		return 0;
	}
	else if(m==1)
	{
		cout<<maxx<<endl;
		return 0;
	}
	else if(m==2)
	{
		int maxs=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int num=a[i]&a[j];
				maxs=max(maxs,num);
			}
		}
		cout<<maxs<<endl;
	}
	else if(n<=30)
	{
		sort(a+1,a+1+n,cmp);
		cout<<dfs(0,1,0)<<endl;
		return 0;
	}
	else if(m==n-1)
	{
		int maxs=0;
		for(int i=1;i<=n;i++)
		{
			int sum;
			if(i==1)
			{
				sum=a[2];
			}
			else
			{
				sum=a[1]; 
			}
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				sum&=a[j];
			}
			maxs=max(maxs,sum);
		}
		cout<<maxs<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
