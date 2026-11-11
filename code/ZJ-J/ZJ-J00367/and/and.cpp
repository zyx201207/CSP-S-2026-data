#include<bits/stdc++.h>
using namespace std;
int n,a[200010],ma,m;
void dfs(int d,int sum,int k)
{
	if(k==m)
	{
		ma=max(ma,sum);
		return ;
	}
	if(d==n+1)
	{
		return ;
	}
	if(sum==-1)
	{
		dfs(d+1,a[d],k+1);
		dfs(d+1,-1,k);
	}
	else
	{
		dfs(d+1,(a[d]&sum),k+1);
		dfs(d+1,sum,k);
	}
	return;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int he=-1,maa=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maa=max(maa,a[i]);
		if(i>1)
		{
			he=(he&a[i]);
		}
		else
		{
			he=a[i];
		}
	}
	if(m==n)
	{
		cout<<he;
		return 0;
	}
	if(m==1)
	{
		cout<<maa;
		return 0;
	}
	if(n<=20)
	{
		dfs(1,-1,0);
		cout<<ma;
		return 0;
	}
	if(n>20&&n<=2000)
	{
		int mm=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				mm=max(mm,(a[i]&a[j]));
			}
		}
		cout<<mm;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}