#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*y;
}
const int N=2e5+7;
int n,m;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int maxn=INT_MIN;
int ans;
void dfs(int u,int p,int yu)
{
	if(u>n||p>m)return;
	if(p==m)
	{
		ans=max(ans,yu);
	}
	dfs(u+1,p+1,yu&a[u+1]);
	dfs(u+1,p,yu);
	return;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]);
	if(m==1)
	{
		cout<<maxn<<"\n";
		return 0;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(n<=25)
	{
		for(int i=1;i<=n;i++)
		{
			dfs(i,1,a[i]); 
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
