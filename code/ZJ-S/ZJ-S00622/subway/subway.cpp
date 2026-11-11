#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const ll N=1e6+10;
ll c,n,m,d,q,qzt[N],dis[N];
vector<pii>gq[N];//,xl[N][21],sj[N][21];
bool vis[N];
struct node
{
	ll l,r,sx,da;
}xw[N];
bool cmp(node x,node y)
{
	return x.l<y.l;
}
bool CMP(node x,node y)
{
	return x.sx<y.sx;
}
void dfs(ll qd)
{
	dis[qd]=0;
	vis[qd]=1;
	queue<ll>q;
	q.push(qd);
	while(q.size())
	{
		ll zj=q.front();
		q.pop();
		if(vis[zj])
		{
			vis[zj]=0;
		}
		for(auto ls:gq[zj])
		{
			ll hz=ls.first,sj=ls.second;
			if(dis[zj]+sj<dis[hz])
			{
				dis[hz]=dis[zj]+sj;
				if(!vis[hz])
				{
					q.push(hz);
					vis[hz]=1;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>qzt[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll sl;
		cin>>sl;
		for(int j=1;j<=sl;j++)
		{
			ll a,b;
			cin>>a>>b;
			//xl[i][j]=a;
			//sj[i][j]=b;
			gq[a].push_back({i+m,b});
			gq[i+m].push_back({a,b});
		}
	}
	for(int i=1;i<=q;i++)
	{
		ll l,r;
		cin>>l>>r;
		xw[i]={l,r,i,qzt[l]+qzt[r]};
	}
	sort(xw+1,xw+1+q,cmp);
	ll sy=0;
	for(int i=1;i<=q;i++)
	{
		if(xw[i].l!=sy)
		{
			memset(dis,0x3f,sizeof dis);
			memset(vis,0,sizeof vis);
			dfs(xw[i].l);
			sy=xw[i].l;
		}
		xw[i].da+=dis[xw[i].r];
	}
	sort(xw+1,xw+1+q,CMP);
	for(int i=1;i<=q;i++)
	{
		cout<<xw[i].da<<"\n";
	}
	/*while(q--)
	{
		ll l,r,ans=0;
		cin>>l>>r;
		ans+=qzt[l];
		ans+=qzt[r];
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		dfs(l);
		cout<<ans+dis[r]<<"\n";
	}*/
	return 0;
}
