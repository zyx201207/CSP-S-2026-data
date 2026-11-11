#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 505;
const int MAXM = 500005;
const ll INF = 1e18;

ll extra[MAXM]; 
ll t[MAXN][MAXM];

int c,n,m,d,q,k;

void init()
{
	for(int i = 0;i < MAXN;i++)
		for(int j = 0;j < MAXM;j++)
			t[i][j] = INF;
}

struct Node
{
	ll curnode,curline;
	ll totdis;
	int type;
	vector<bool> vis;
};

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	init();
	for(int i = 1;i <= m;i++)
		cin>>extra[i];
	for(int i = 1;i <= n;i++)
	{
		cin>>k;
		for(int j = 1;j <= k;j++)
		{
			ll a,b;
			cin>>a>>b;
			t[i][a] = b;
		}
	}
	
	while(q--)
	{
		ll ans = INF;
		ll st,ed;
		cin>>st>>ed;
		queue<Node> q;
		vector<bool> vis(MAXM + 5,false);
		vis[st] = true;
		for(ll line = 1;line <= n;line++)
			q.push((Node){st,line,t[line][st],0,vis});
		while(!q.empty())
		{
			Node tmp = q.front();
			ll newdis = tmp.totdis;
			vector<bool> newvis = tmp.vis;
			q.pop();
			if(tmp.type == 0)
			{
				for(ll to = 1;to <= m;to++)
				{
					if(tmp.curnode == to or tmp.vis[to]) continue;
					if(t[tmp.curline][to] == INF) continue;
					newvis[to] = true;
					newdis += t[tmp.curline][to];
					q.push((Node){to,tmp.curline,newdis,1,newvis}); 
				}
			}
			else
			{
				if(tmp.curnode == ed)
				{
					ans = min(ans,tmp.totdis);
					continue;
				} 
				for(ll line = 1;line <= n;line++)
				{
					if(line == tmp.curline) continue;
					q.push((Node){tmp.curnode,line,tmp.totdis + t[line][tmp.curnode],0,tmp.vis});
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}