#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll c,n,m,d,q,T;
ll ans;
ll w[N];
vector<ll> zhan[N];//记录每个站所在的所有线 
int t[500][N];
ll ya=0;
struct eg{
	ll to,nxt;
}e[N];
ll cnt,head[N];
void add(ll u,ll v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
struct dian{
	ll u,xi,pre,use;
};
void bfs(ll st1,ll st2,ll xi,ll end)
{
	deque<dian> q;
	q.push_back({st2,xi,st1,ya});
	while(!q.empty())
	{
		dian now=q.front();
		q.pop_front();
		int u=now.u;
		if(u==end)
		{
			ll ling=now.use+t[now.xi][end];
			ans=min(ans,ling);
			continue;
		 } 
		ll f=now.xi;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(v==now.pre)continue;
			ll sam=0;
			for(int j=0;j<zhan[u].size();j++)
			{
				for(int p=0;p<zhan[v].size();p++)
				{
					if(zhan[u][j]==zhan[v][p])
					{
						sam=zhan[v][p];
						if(sam==f)q.push_front({v,f,u,now.use});
						else 
						{
							if(now.use+t[f][u]+t[sam][u]<=ans)
							{
								q.push_back({v,sam,u,now.use+t[f][u]+t[sam][u]});
							}
						}
					}
				}
			}
		}
	}
	return;
}

void solve(int st,int end)
{
	ans=INT_MAX;
	for(int i=head[st];i;i=e[i].nxt)
	{
		ll v=e[i].to;
		ll sam=-1;
		for(int j=0;j<zhan[st].size();j++)
		{
			for(int p=0;p<zhan[v].size();p++)
			{
				if(zhan[st][j]==zhan[v][p])
				{
					sam=zhan[st][j];
					if(v==end)
					{
						ll ya=w[st]+t[sam][st]+t[sam][end]+w[end];
						ans=min(ans,ya);
					}else{
						ya=w[st]+t[sam][st]+w[end];//st->厅->线+end厅->end口 
						bfs(st,v,sam,end);
					}
					
				}
			}
		}
	}
	cout<<ans<<"\n";
	return ;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		ll pre=0;
		for(int j=1;j<=k;j++)
		{
			int a,t1;
			cin>>a>>t1;
			t[i][a]=t1;
			if(pre!=0)
			{
				add(pre,a);
				add(a,pre);
			}
			pre=a;
			zhan[a].push_back(i);
		}
	}
	while(q--)
	{
		ll st,ed;
		cin>>st>>ed;
		solve(st,ed);
	}
	return 0;
}
