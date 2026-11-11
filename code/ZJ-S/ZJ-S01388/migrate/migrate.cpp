#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define ll long long

using namespace std;
const ll INF=1e16;
const int N=1e6+7;
int n,d,cnt[N];
ll x[N],dis[N],ans;
struct node
{
	int pos;
	ll step;
};
void bfs(int st)
{
	for(int i=1;i<=n;i++)
	  dis[i]=INF;
	memset(cnt,0,sizeof(cnt));
	queue<node> q;
	q.push({st,0ll});
	while(!q.empty())
	{
		node now=q.front(); q.pop();
		for(int i=now.pos+1;i<=n&&x[i]-x[now.pos]<=d;i++)
		{
			if(dis[i]>now.step+1)
			{
				cnt[i]=1;
				dis[i]=now.step+1;
				q.push({i,dis[i]});
			}
			else if(dis[i]==now.step+1)
			{
				cnt[i]++;
				q.push({i,dis[i]});
			}
		}
		if(now.pos<n&&x[now.pos+1]-x[now.pos]>d)
		  break;
	}
	for(int i=st+2;i<=n;i++)
	  if(cnt[i]==2)
	    ans++;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; cin>>c>>t;
	while(t--)
	{
		ans=0ll;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		  cin>>x[i];
		for(int i=1;i<n;i++)
		  bfs(i);
		cout<<ans<<"\n";
	}
	return 0;
}
