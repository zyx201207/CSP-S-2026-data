#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+2;
int a[N],l,r,n,m,maxx,ans,used[N],b[N];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x)
{
	if(x>m)
	{
		int sum=b[1];
		for(int i=2;i<=m;i++)sum&=b[i];
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			used[i]=1;
			b[x]=a[i];
			dfs(x+1);
			b[x]=0;
			used[i]=0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(n<=20)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	else if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxx=max(maxx,a[i]&a[j]);
		cout<<maxx;
		return 0;
	}
	else if(m==n)
	{
		maxx=a[1];
		for(int i=2;i<=n;i++)maxx=maxx&a[i];
		cout<<maxx;
		return 0;
	}
	else if(m==n-1)
	{
		maxx=a[1];
		for(int i=2;i<=n-1;i++)maxx=maxx&a[i];
		cout<<maxx;
		return 0;
	}
	else
	{
		maxx=a[1];
		int sum=a[2];
		for(int i=2;i<=m;i++)maxx&=a[i],sum&=a[i];
		if(m+1<=n)cout<<max(maxx,sum&a[m+1]);
		else cout<<maxx;
	}
}
