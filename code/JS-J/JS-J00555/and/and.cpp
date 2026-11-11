#include<bits/stdc++.h>
using namespace std;
int v[200010],t;
unsigned long long n,m,a[200010],b[200010],num;
void dfs(long long k)
{
	if(t==m)
	{
		num=max(num,b[t]);
		return;
	}
	if(t+n-k+1<m||k>n)
		return;
	for(int i=1;i<=2;i++)
	{
		if(i==1&&v[k]==0)
		{
			v[k]=1;
			t++;
			if(t==1)
				b[t]=a[k];
			else
				b[t]=b[t-1]&a[k];
			dfs(k+1);
			v[k]=0;
			b[k]=0;
			t--;
		}
		else
			dfs(k+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)
			m=max(m,a[i]);
		cout<<m;
		return 0;
	}
	if(m==n)
	{
		num=a[1];
		for(int i=2;i<=n;i++)
			num=num&a[i];
		cout<<num;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				num=max(num,a[i]&a[j]);
		cout<<num;
		return 0;
	}
	dfs(1);
	cout<<num;
	return 0;
}