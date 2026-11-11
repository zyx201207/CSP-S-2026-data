#include<bits/stdc++.h>
using namespace std;
#define pl pair<int,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define int long long
const int N=5e5+5e2+5e0,MX=LONG_LONG_MAX;
int n,m,d,q,wk[N],num,dis[N],kel,tg[N];
priority_queue<pl,vector<pl>,greater<pl> > p;
queue<int> dq;
bool vis[N];
vector<pl> v[N];
vector<int> lp[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>num>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>wk[i];
	if(12<=num&&num<=19)
	{
		for(int i=1;i<=n;i++)
		{
			int siz,cnt=m+i,to,val;
			cin>>siz;
			for(int j=1;j<=siz;j++)
			{
				cin>>to>>val;
				kel=val;
				lp[cnt].push_back(to);
				lp[to].push_back(cnt);
			}
		}
		for(int i=1;i<=q;i++)
		{
			int st,en;
			cin>>st>>en;
			for(int j=1;j<=n+m;j++)tg[j]=0;
			tg[st]=1;
			dq.push(st);
			while(!dq.empty())
			{
				int fr=dq.front();
				dq.pop();
				for(int j=0;j<lp[fr].size();j++)
				{
					int to=lp[fr][j];
					if(tg[to])continue;
					tg[to]=tg[fr]+1;
					if(to==en)
					{
						while(!dq.empty())dq.pop();
						cout<<wk[st]+wk[en]+tg[fr]*kel<<'\n';
						break;
					}
					dq.push(to);
				}
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int siz,cnt=m+i,to,val;
		cin>>siz;
		for(int j=1;j<=siz;j++)
		{
			cin>>to>>val;
			v[cnt].push_back(mp(to,val));
			v[to].push_back(mp(cnt,val));
		}
	}
	for(int i=1;i<=n+m;i++)dis[i]=MX;
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n+m;j++)dis[j]=MX;
		for(int j=1;j<=n+m;j++)vis[j]=0;
		int st,en;
		cin>>st>>en;
		dis[st]=0;
		p.push(mp(0,st));
		while(!p.empty())
		{
			pl t=p.top();
			p.pop();
			int f=t.fi,s=t.se;
			if(vis[s])continue;
			if(s==en)
			{
				while(!p.empty())p.pop();
				cout<<f+wk[st]+wk[en]<<'\n';
				break;
			}
			vis[s]=1;
			for(int j=0;j<v[s].size();j++)
			{
				pl l=v[s][j];
				int to=l.fi,val=l.se;
				if(dis[to]>f+val)
				{
					dis[to]=f+val;
					p.push(mp(dis[to],to));
				}
			}
		}
	}
	return 0;
}