#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,tot;
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool fa=true,fb=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(fa && a[i]!=i) fa=false;
		if(fb && i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2]) fb=false;
	}
	if(fa)
	{
		int delt=sqrt(1+8*m);
		int x=(delt-1)/2;
		cout<<x+1;
		return 0;
	}
	if(fb)
	{
		int d=a[2]-a[1];
		int delt=sqrt(d*d+8*d*m);
		int x=(delt-d)/(2*d);
		cout<<x+1;
		return 0;
	}
	if(m<=1000000)
	{
		while(tot<m)
		{
			int sum=0;
			for(int i=1;i<=n;i++) sum+=a[i];
			int mid=sum/n;
			for(int i=1;i<=n;i++)
			{
				if(a[i]>=mid) break;
				if(tot+(mid-a[i]) > m) { tot=m;break; }
				tot+=(mid-a[i]);
				a[i]=mid;
			}
		}
		sort(a+1,a+n+1); 
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				cout<<i-1;
				return 0;
			}
		}
		return 0;
	}
	sort(a+1,a+n+1);
	int tar=a[n],cnt=0;
	tot=0;
	for(int i=n;i>=1;i--)
	{
		if(tot+tar-a[i]>m) break;
		tot+=(tar-a[i]);
		a[i]=tar;
		cnt++;
	}
	cout<<cnt+1;
	return 0;
} 
