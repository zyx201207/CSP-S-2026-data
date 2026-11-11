#include<bits/stdc++.h>
using namespace std;
int a[200010],pre[200010];
bool b[200010];
int ans1=INT_MIN;
int n,m;
void dfs(int sum,int dang,bool b[])
{
	if(sum==m)
	{
		if(dang>ans1)
			ans1=dang;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==false)
		{
			b[i]=true;
			dfs(sum+1,dang&a[i],b);
			b[i]=false;
		}
	} 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=true;
			int dang = a[i];
			dfs(1,dang,b);
			b[i]=false;
		}
			
		cout << ans1;
	}
	else if(m==1)
	{
		sort(a+1,a+n+1);
		cout << a[n];
	}
	else if(m==n)
	{
		int ans2=a[1];
		for(int i=2;i<=n;i++) 
		{
			ans2=ans2&a[i];
		}
		cout << ans2;
	}
	else if(m==2)
	{
		int ans3=INT_MIN;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) 
			{
				if(i!=j)
				{
					ans3=max(ans3,a[i]&a[j]);
				}
			}
		cout << ans3;
	}
	else if(m==n-1)
	{
		int ans4=INT_MIN,pos2;
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
			{
				pos2=a[1];
			}
			else
			{
				pos2=a[2];
			}
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					pos2=pos2&a[j];
				}
			}
			ans4=max(pos2,ans4);
		}
		cout << ans4;	
	}
	else
		cout << 0;
}
