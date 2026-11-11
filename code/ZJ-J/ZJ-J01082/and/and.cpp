#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
long long a[N];
long long b[N];
long long mx=-1e9;
void dfs(int deep,int y)
{
	if(deep==m+1)
	{
		long long sum=b[1];
		for(int i=2;i<=m;i++)
		{
			sum=sum&b[i];
		}
		mx=max(mx,sum);
		return ;
	}
	else
	{
		for(int i=y;i<=n;i++)
		{
			b[deep]=a[i];
			dfs(deep+1,i+1);
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=1e4-100)
	{
		dfs(1,1);
		cout<<mx;
	}
	else
	{
		bool flag_b=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==i-1) flag_b=1;
			else
			{
				flag_b=0;
				break;
			}
		}
		if(flag_b==1)
		{
			cout<<676767;
		}
		else
		{
			sort(a+1,a+1+n);
			cout<<a[n-m+1];
		}
	}
	return 0;
}