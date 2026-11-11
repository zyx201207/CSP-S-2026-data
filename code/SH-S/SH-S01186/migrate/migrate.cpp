#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,d;
int a[5005];
int len[505][505];
int cnt[505][505];
int path[505];
void dfs(int x)
{
	if(x==n+1)
	{
		int now=0,next=0;
		int s,e,l=0;
		while(path[now]==0 && now<=n) now++;
		if(now>n) return;
		next=now+1;
		while(path[next]==0 && next<=n) next++;
		if(next>n) return;
		s=now;
		while(next<=n)
		{
			if(a[next]-a[now]>d) return;
			l++;
			now=next;
			next++;
			while(path[next]==0 && next<=n) next++;
		}
		e=now;
		if(len[s][e]==-1 || l<len[s][e])
		{
			len[s][e]=l;
			cnt[s][e]=1;
		}
		else if(l==len[s][e])
		{
			cnt[s][e]++;
		}
		return;
	}
	path[x]=0;
	dfs(x+1);
	path[x]=1;
	dfs(x+1);
}
void solve()
{
	int ans,i,j;
	memset(len,-1,sizeof(len));
	memset(cnt,0,sizeof(cnt));
	dfs(1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			if(cnt[j][i]==2) ans++;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,i;
	cin>>C>>T;
	for(t=0;t<T;t++)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++) cin>>a[i];
		solve();
	}
}
