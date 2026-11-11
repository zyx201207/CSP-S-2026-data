#include<bits/stdc++.h>
using namespace std;
const int N=2e5+200;
int vis[N];
int n,m,a[N],flaga=1,maxa;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int t=a[i]+1;
		if((t&(-t))!=a[i]) flaga=0;
		maxa=max(maxa,a[i]);
	}
	if(m==1)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
			maxn=max(a[i],maxn);
		cout<<maxn;
		return 0;
	}
	if(m==n-1)
	{
		int t=a[1],maxn=0;
		for(int i=2;i<=n;i++)
			t=(t&a[i]);
		for(int i=1;i<=n;i++)
		{
			int x=(~a[i]);
			maxn=max(maxn,t&x);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2&&n<=25000)
	{
		int maxn;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
		return 0;
	}
	if(flaga)
	{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	if(maxa<4)
	{
		int b[10]={0},u=3,t=3;
		for(int i=1;i<=n;i++)
			b[a[i]]++;
		while(!b[u]) t--,u--;
		for(int i=1;i<=m;i++)
		{
			if(b[u]) t=(t&u);
			else u--;
		}
		cout<<t;
		return 0;
	}
	sort(a+1,a+1+n);
	int t=a[n];
	for(int i=2;i<=m;i++)
		t&=a[n-i+1];
	cout<<t;
	return 0;
}