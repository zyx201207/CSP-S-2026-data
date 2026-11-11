#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool cmp(long long x,long long y)
{
	return x>y ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(m==1)
	{
		long long maxx=-1;
		for(int i=1;i<=n;++i) maxx=max(maxx,a[i]);
		cout<<maxx; 
	}
	else if(m==2)
	{
		sort(a+1,a+n+1);
		long long maxx=a[n] and a[n-1];
		for(int i=1;i<=n-1;++i)
		{
			maxx=max(maxx,(a[i]&a[i+1]));
		}
		cout<<maxx;
	}
	else if(m==n)
	{
		sort(a+1,a+n+1,cmp);
		long long ans=a[1]&a[2];
		for(int i=3;i<=m;++i)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else 
	{
		sort(a+1,a+n+1,cmp);
		long long maxx=-1;
		for(int i=1;i<=m;i++)
		{
			maxx=a[i]&a[i-1]; 
		}
		cout<<maxx;
	}
	return 0;
}
