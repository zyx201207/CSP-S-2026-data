#include<bits/stdc++.h>
typedef long long ll;
//#define debug
using namespace std;
struct line {
	int to,w;
};
const int M=5e5,D=25,N=505;
vector<long long>dis[M];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
vector<line>v[N+M];
ll w[M];
int c,n,m,d;
void dijkstra(int st) {
	static long long d[N];
	memset(d,0b01111111,sizeof d);
	q.push(make_pair(0,st));
	d[st]=0;
	int len,now,nxt,ww;
	while(!q.empty()) {
		len=q.top().first,now=q.top().second;
		q.pop();
		if(len!=d[now])
			continue;
		for(int i=0; i<v[now].size(); i++) {
			ww=v[now][i].w;
			nxt=v[now][i].to;
			if(d[nxt]>d[now]+ww) {
				d[nxt]=d[now]+ww;
				q.push(make_pair(d[nxt],nxt));
				if(nxt>m)
					dis[st][nxt-m]=d[nxt];
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1,j,k,a,t; i<=n; i++) {
		cin>>k;
		for(j=1; j<=k; j++) {
			cin>>a>>t;
			v[a].push_back((line) {
				i+m,t
			});
			v[i+m].push_back((line) {
				a,t
			});
		}
	}
	long long ans;
	for(int i=1,j,l,r; i<=q; i++) {
		ans=LLONG_MAX;
		cin>>l>>r;
		if(dis[l].empty()) {
			dis[l].resize(n+2);
			dijkstra(l);
		}
		if(dis[r].empty()) {
			dis[r].resize(n+2);
			dijkstra(r);
		}
		for(j=1; j<=n; j++)
			ans=min(ans,dis[l][j]+dis[r][j]);
		cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}

