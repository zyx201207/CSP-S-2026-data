#include<bits/stdc++.h>
using namespace std;
#define se second
#define fi first
struct node {
	long long v,w;
};
struct node1 {
	long long id,k;
};
long long c,n,m,d,q;
node1 a[505][50005];
long long t[100005],dis[100005];
long long w[1000005],k[505],cnt,ans;
vector <long long> v[100005];
vector <node> vv[100005];
bool vis[100005];
long long idd[505][50005];
bool viss[505];
void dj(long long l) {
	priority_queue <pair< long long,long long > > q;
	q.push({0ll,l});
	while(!q.empty()) {
		pair<long long,long long> qq=q.top();
		q.pop();
		long long qqs=qq.se,qqf=qq.fi;
		if(!viss[qqs]) {
			viss[qqs]=1;
			for(long long i=0; i<vv[qqs].size(); ++i) {
				if(dis[vv[qqs][i].v]>dis[qqs]+vv[qqs][i].w) {
					dis[vv[qqs][i].v]=dis[qqs]+vv[qqs][i].w;
					if(!viss[vv[qqs][i].v]) {
						q.push({dis[vv[qqs][i].v],vv[qqs][i].v});
					}
				}
			}

		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
//	if(c>=12 && c<=19){
//		
//	}
	for(long long i=1; i<=m; ++i) scanf("%lld",&w[i]);
	for(long long i=1; i<=n; ++i) {
		cin>>k[i];
		for(long long j=1; j<=k[i]; ++j) {
			scanf("%lld%lld",&a[i][j].id,&a[i][j].k);
			v[a[i][j].id].push_back(i);
			idd[i][a[i][j].id]=j;
		}
	}
	for(long long i=1; i<=n; ++i) {
		for(long long j=1; j<=k[i]; ++j) {
			if(v[a[i][j].id].size()>1 && !vis[a[i][j].id]) {
				t[++cnt]=a[i][j].id;
				vis[a[i][j].id]=1;
			}
		}
	}
	for(long long i=1; i<=cnt; ++i) {
		for(long long j=0; j<v[t[i]].size(); ++j) {
			for(long long k=j+1; k<v[t[i]].size(); ++k) {
				vv[v[t[i]][j]].push_back({v[t[i]][k],a[v[t[i]][j]][idd[v[t[i]][j]][t[i]]].k+a[v[t[i]][k]][idd[v[t[i]][k]][t[i]]].k});
				vv[v[t[i]][k]].push_back({v[t[i]][j],a[v[t[i]][j]][idd[v[t[i]][j]][t[i]]].k+a[v[t[i]][k]][idd[v[t[i]][k]][t[i]]].k});
			}
		}
	}
	while(q--) {
		long long l,r;
		ans=1e9;
		cin>>l>>r;
		for(long long i=0; i<v[l].size(); ++i) {
			for(long long j=0; j<v[r].size(); ++j) {
				if(v[l][i]==v[r][j]) {
					ans=min(ans,w[l]+a[v[l][i]][idd[v[l][i]][l]].k+w[r]+a[v[r][j]][idd[v[r][j]][r]].k);
				} else {
					for(long long i=1; i<=n; ++i) dis[i]=1e9;
					dis[v[l][i]]=0;
					memset(viss,0,sizeof viss);
					dj(v[l][i]);
					ans=min(ans,dis[v[r][j]]+w[l]+a[v[l][i]][idd[v[l][i]][l]].k+w[r]+a[v[r][j]][idd[v[r][j]][r]].k);
				}
			}
		}
	cout<<ans<<'\n';
	}
	
}
