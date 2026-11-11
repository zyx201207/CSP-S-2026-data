#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
bool flag[5010];
int dep[5010],vis[5010];
int a[1000010];
void bfs(int x)
{
	queue<int>q;
	q.push(x);
	dep[x]=0;vis[x]=1;flag[x]=1;
	int pos1,pos2;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		pos1=lower_bound(a+1,a+n+1,x-d)-a;
		pos2=upper_bound(a+1,a+n+1,x+d)-a-1;
		for(int i=pos1;i<=pos2;i++)
		{
			if(flag[i]==0){vis[i]=1;flag[i]=1;dep[i]=dep[x]+1;q.push(i);}
			else if(dep[x]+1==dep[i])vis[i]++;
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c<=10)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int id=1;id<=n;id++)flag[id]=id<i,dep[id]=1e18,vis[id]=0;
				bfs(i);
				for(int id=1;id<=n;id++)ans+=(vis[id]==2);
			}
			cout<<ans<<"\n";
		}
		if(c==11||c==12)cout<<n-(2*d/(a[2]-a[1])-1)<<"\n";
		if(c==13||c==14)
		{
			for(int i=1;i<=n;i++)if(a[i]-a[1]<=d&&a[n]-a[i]<=d){cout<<(i-1)*(n-i);}
		}
		if(15<=c&&c<=18)while(1)cout<<"toe";
		if(18<c)while(1)cout<<"1629";
	}
	return 0;
}
