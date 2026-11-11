#include<bits/stdc++.h>
using namespace std;
long long w[500002];
long long k[502];
long long cnt[500002];
vector<long long> zhan1[500002],zhan2[500002];
vector<pair<long long,long long> > a[502];
long long b[502];
long long zdl[502][502];
long long c,n,m,d,q;
bool v[502];
priority_queue<pair<long long,long long> > qu;
void dij(long long u){
	memset(v,0,sizeof(v));
	zdl[u][u]=0;
	qu.push({0,u});
	while(!qu.empty()){
		while(!qu.empty()&&v[qu.top().second]){
			qu.pop();
		}
		if(qu.empty()){
			break;
		}
		pair<long long,long long> pr=qu.top();
		qu.pop();
		long long x=pr.second,z=-pr.first;
		v[x]=1;
		for(long long i=0;i<b[x];i++){
			long long y=a[x][i].first,zz=a[x][i].second;
			if(zdl[u][y]>z+zz){
				zdl[u][y]=z+zz;
				qu.push({-(z+zz),y});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
//	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(zdl,127,sizeof(zdl));
	for(long long i=1;i<=m;i++){
		cin>>w[i];
//		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
//		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++){
			long long x,y;
			cin>>x>>y;
//			scanf("%lld%lld",&x,&y);
			zhan1[x].push_back(i);
			zhan2[x].push_back(y);
			cnt[x]++;
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<cnt[i];j++){
			for(long long k=j+1;k<cnt[i];k++){
				a[zhan1[i][j]].push_back({zhan1[i][k],zhan2[i][j]+zhan2[i][k]});
				a[zhan1[i][k]].push_back({zhan1[i][j],zhan2[i][j]+zhan2[i][k]});
				b[zhan1[i][k]]++;
				b[zhan1[i][j]]++;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		dij(i);
	}
	while(q--){
		long long x,y,ans=100000000000000009ll;
		cin>>x>>y;
//		scanf("%lld%lld",&x,&y);
		for(long long i=0;i<cnt[x];i++){
			for(long long j=0;j<cnt[y];j++){
				ans=min(ans,w[x]+w[y]+zdl[zhan1[x][i]][zhan1[y][j]]+zhan2[x][i]+zhan2[y][j]);
			}
		}
		cout<<ans<<"\n";
//		printf("%lld\n",ans);
	}
	return 0;
}
