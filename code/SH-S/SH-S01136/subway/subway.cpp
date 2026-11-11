#include <bits/stdc++.h>
#define use(x) using std::x;
#define pb push_back
#define fastread ios::sync_with_stdio(false),cin.tie(0);
#define freo(a,b) freopen(a,"r",stdin),freopen(b,"w",stdout);
#define fi first
#define se second
#define int long long
#define pii pair<int,int>
use(fill)use(priority_queue)use(greater)use(deque)
use(cin)use(sort)use(max)use(cout)use(ios)use(pair)use(vector)use(swap)
const int maxn=505;
const int maxm=500005;
const int maxd=25;
const int maxq=100005;
pair<pii,pii> xy[maxq];// {{x,y},{i,ans}}


int w[maxm];

vector<pii> g[maxm+maxn];
int dist[maxm+maxn];

bool cmp(pair<pii,pii>&a, pair<pii,pii>&b)
{
	return a.se.fi<b.se.fi;
}

signed main()
{
	freo("subway.in","subway.out")
	fastread
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;	
	
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	
	// k+maxm
	// i是线路名
	// i+maxm是表示k号线的节点 
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int j=0;j<k;j++)
		{
			int a,t;
			cin>>a>>t;
			// cout<<a<<' '<<t<<' ';
			g[a].pb({t,i+maxm});
			g[i+maxm].pb({t,a});
		}
	}
	
	for (int i=0;i<q;i++)
	{
		cin>>xy[i].fi.fi>>xy[i].fi.se;
		if (xy[i].fi.fi>xy[i].fi.se) swap(xy[i].fi.fi,xy[i].fi.se);
		xy[i].se.fi=i;
		// cout<<xy[i].fi.fi<<xy[i].fi.se;
	}
	sort(xy,xy+q);
	int pre=-1;
	for (int p=0;p<q;p++)
	{
		
		
		if (c>=16 && c<=19)
		{
			
			int x=xy[p].fi.fi;
		int y=xy[p].fi.se;
		if (pre==x)
		{
			xy[p].se.se=dist[y];
			continue;
		}
		pre=x; 
			#define p abc114514
			deque<pii> p;
			p.pb({0,x});
			while (!p.empty())
			{
				pii top=p.front();
				p.pop_front();
				for (auto i:g[top.se])
				{
					if (dist[i.se]) continue;
					dist[i.se]=dist[top.se]+1;
					p.pb({dist[i.se],i.se});
				}
			}
			#undef p
			xy[p].se.se=dist[y]*g[maxm+1][0].fi;
			continue;
			
			
		}
		int x=xy[p].fi.fi;
		int y=xy[p].fi.se;
		if (pre==x)
		{
			xy[p].se.se=dist[y];
			continue;
		}
		pre=x; 
		
		fill(dist,dist+maxm+maxn,0x3f3f3f3f3f3f3fll);
		dist[x]=0;
		// cout<<123<<x<<123;
		priority_queue<pii,vector<pii>,greater<pii>> heap;
		// cout<<heap.empty()<<1145;
		heap.push({0,x});
		// cout<<heap.top().fi<<' '<<heap.size();
		// cout<<y<<'\n';
		while (!heap.empty())
		{
			pii top=heap.top();
			heap.pop();
			// cout<<dist[top.se]<<' ';
			if (top.fi>dist[top.se]) continue;
			for (pii nxt:g[top.se])
			{
				//  cout<<'\n'<<top.se<<' '<<nxt.se<<'\n';
				if (top.fi+nxt.fi>=dist[nxt.se]) continue;
				// cout<<top.fi<<' '<<nxt.fi<<' ';
				heap.push({top.fi+nxt.fi,nxt.se});
				
				dist[nxt.se]=top.fi+nxt.fi;
				// cout<<dist[1]<<"c";
			}
		}
		
		// for (int i=0;i<10;i++) cout<<dist[i]<<' ';
		xy[p].se.se=dist[y];
		// cout<<"aaa:"<<xy[p].se.se<<"aaa";;
		
	}
	sort(xy,xy+q,cmp);
	for (int i=0;i<q;i++) cout<<xy[i].se.se+w[xy[i].fi.fi]+w[xy[i].fi.se]<<'\n';
	
	 
	
} 
