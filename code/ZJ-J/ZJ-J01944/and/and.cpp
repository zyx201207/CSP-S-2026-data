#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],b[200005],ans;
bool vis[200005];
void f(int x)
{
	if(x==m+1)
	{
		long long cnt=b[1]&b[2];
		for(int i=3;i<=m;i++)
			cnt&=b[i];
		ans=max(cnt,ans);
		return;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
		{
			b[x]=a[i];
			vis[i]=1;
			f(x+1);
			vis[i]=0;
		}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n>2000)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<'\n';
		return 0;
	}
	f(1);
	cout<<ans<<'\n';
	return 0;
}
