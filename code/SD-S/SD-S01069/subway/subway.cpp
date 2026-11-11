#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 5e2 + 10;
const int M = 5e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll _,n,m,d,q;
ll w[M],dis[N+M],vi[N];
vector<pair<int,ll> > a[N+M];
void zdl(int s) {
	priority_queue<pair<ll,int> > q;
	for(int i=1;i<=n+m;i++) dis[i]=INF; 
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()) {
		pair<ll,int> p=q.top();
		int x=p.second;
		q.pop();
		for(int i=0;i<a[x].size();i++) {
			int y=a[x][i].first;
			ll z=a[x][i].second;
			if(dis[x]+z<dis[y]) {
				dis[y]=dis[x]+z;
				q.push({dis[y],y});
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&_,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i) {
		ll k;
		scanf("%lld",&k);
		for(int j=1;j<=k;++j) {
			ll x,y;
			scanf("%lld %lld",&x,&y);
			a[x].push_back({m+i,y});
			a[m+i].push_back({x,y});
		}
	}
	int last=0;
	while(q--) {
		int x,y;
		scanf("%d %d",&x,&y);
		if(x==last) printf("%lld\n",dis[y]+w[x]+w[y]);
		else {
			zdl(x);
			printf("%lld\n",dis[y]+w[x]+w[y]);
		} 
		last=x;
	}
	return 0;
}
