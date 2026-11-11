#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	} 
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		int ans=-1e5;
		for(int i=1;i<=n;i++)
		{
			int aans=a[1];
			for(int j=1;j<=n;j++)
				if(j!=i) aans=(aans&a[j]);
			if(aans>ans) ans=aans;
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		int ans=-1e6;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				if(ans<(a[i]&a[j])) ans=(a[i]&a[j]);
 		}
 		cout<<ans;
 		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;i++) ans=(ans&a[i]);
	cout<<ans;
	return 0;
}

