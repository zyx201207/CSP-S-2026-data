#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500010],cnt[600010],ans[100010];
pair<pair<int,int>,int> p[100010];
long long w[600010],t[500010],dis[20000010];
bool vis[20000010];
vector<pair<long long,int> > g[6000010];
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
	return a.first.first<b.first.first;
}
void solve(int u){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[u]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
	q.push({dis[u],u});
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0;i<g[x].size();i++){
			long long w=g[x][i].first;
			int y=g[x][i].second;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push({dis[y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m;
	cin >> d >> q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d %lld",&a[j],&t[j]);
			cnt[a[j]]++;
			g[20*a[j]+cnt[a[j]]-1].push_back({t[j],a[j]});
			g[a[j]].push_back({t[j],20*a[j]+cnt[a[j]]-1});
			if(j>1){
				g[20*a[j-1]+cnt[a[j-1]]-1].push_back({0,20*a[j]+cnt[a[j]]-1});
				g[20*a[j]+cnt[a[j]]-1].push_back({0,20*a[j-1]+cnt[a[j-1]]-1});
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&p[i].first.first,&p[i].first.second);
		p[i].second=i;
	}
	sort(p+1,p+q+1,cmp);
	for(int i=1;i<=q;i++){
		if(p[i].first.first!=p[i-1].first.first){
			solve(p[i].first.first);
		}
		ans[p[i].second]=dis[p[i].first.second]+w[p[i].first.first]+w[p[i].first.second];
	}
	for(int i=1;i<=q;i++){
		cout << ans[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
