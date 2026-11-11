#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int sel[MAXN];
int n,m;
int ans=-1;
void dfs(int step,int v)
{
	if(step==m)
	{
		int sum=sel[0];
		for(int i=1;i<m;i++)
		{
			sum=sum&sel[i];
		}
		ans=max(ans,sum);
	}
	for(int i=v;i<n;i++)
	{
		sel[step]=a[i];
		if(m-step>n-i)
		{
			return;
		}
		dfs(step+1,i+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		dfs(0,0);
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		int ans1=-1;
		for(int i=0;i<n;i++)
		{
			ans1=max(ans1,a[i]);
		}
		cout<<ans1;
		return 0;
	}
	if(m==2)
	{
		int ans3=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ans3=max(ans3,a[i]&a[j]);
			}
		}
		cout<<ans3;
		return 0;
	}
	if(m==n)
	{
		int ans2=a[0];
		for(int i=1;i<n;i++)
		{
			ans2=ans2&a[i];
		}
		cout<<ans2;
		return 0;
	}
	if(m==n-1)
	{
		int ans4=-1;
		int sum=a[1];
		for(int j=2;j<n;j++)
		{
			sum=sum&a[j];
		}
		ans4=max(ans4,sum);
		for(int i=1;i<n;i++)
		{
			int sum=a[0];
			for(int j=1;j<n;j++)
			{
				if(j==i) continue;
				sum=sum&a[j];
			}
			ans4=max(ans4,sum);
		}
		cout<<ans4;
		return 0;
	}
	return 0;
}
