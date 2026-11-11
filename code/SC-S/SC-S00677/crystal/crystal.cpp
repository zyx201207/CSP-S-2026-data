#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;

long long a[maxn],d[maxn],pre[maxn],n,m;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
		
	
	int r=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(a[r]*(r-i+1)<=m+pre[r]-pre[i-1] && r<=n) r++;
//		cout<<i<<' '<<r<<'\n';
		ans=max(ans,r-i);
	}
	
	cout<<ans;
	
	return 0;
}