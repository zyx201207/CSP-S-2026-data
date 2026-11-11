#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[25];
int dfs(int dl,int gs,int m)
{
	if(gs>m||dl>n){
		long long ji=b[1];
		for(int i=2;i<=m;i++)
		{
			if (b[i]>=0)
				ji=(ji&b[i]);
		}
		return ji;
	}
	b[gs]=a[dl];
	gs++;
	int zj=dfs(dl+1,gs,m);
	b[gs]=-1;
	gs--;
	int zh=dfs(dl+1,gs,m);
	return max(zj,zh);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (m==n)
	{
		long long sum=a[1];
		for (int i=2;i<=n;i++)
		{
			sum=(sum&a[i]);
		}
		cout<<sum;
	}
	else if (m==1)
	{
		sort(a,a+n+1);
		cout<<a[n];
	}
	else if (m==n-1)
	{
		sort(a,a+n+1);
		cout<<a[1];
	}
	else if (m==2)
	{
		long long maxx=-1;
		for (int i=1;i<n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				long long kk=(a[i]&a[j]);
				maxx=max(maxx,kk);
			}
		}
		cout<<maxx;
	}
	if (m<=n&&n<=20)
	{
		cout<<dfs(1,1,m);
	}
	return 0;
}
