#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const long long N=5e5+7,inf=1e18+7;
long long tim[N],n,vis[N],cld[N];
vector<pair<long long,long long> > vec[N],tree[N];
vector<long long> crs,rep;
long long dfs(long long now,long long b,long long sum,long long bk){
	if(vis[now]){
		return inf;
	}
	if(cld[now]){
		long long l=vec[b].size();
		for(long long i=0;i<l;i++){
			if(vec[b][i].first==now){
				return sum+vec[b][i].second;
			}
		}
	}
	long long len=tree[now].size(),ans=inf;
	for(long long i=0;i<len;i++){
		vis[now]=1;
		ans=min(ans,dfs(tree[now][i].first,b,sum+tree[now][i].second,now));
		vis[now]=0;
		//cout<<now<<" "<<ans<<endl;
	}
	return ans;
}
void check(){
	for(long long i=0;i<=n+1;i++){
		long long len=tree[i].size();
		for(long long j=0;j<len;j++){
			printf("%lld %lld %lld\n",i,tree[i][j].first,tree[i][j].second);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&tim[i]);
	}
	for(long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			long long a,b;
			scanf("%lld%lld",&a,&b);
			if(vec[a].size()==1){
				crs.pb(a);
			}
			vec[a].pb(mp(i,b));
		}
	}
	long long l3=crs.size();
	for(long long i=0;i<l3;i++){
		rep.clear();
		long long k=crs[i],len=vec[k].size();
		for(long long j=0;j<len;j++){
			rep.pb(vec[k][j].first);
		}
		for(long long a=0;a<len;a++){
			for(long long b=a+1;b<len;b++){
				long long di=vec[k][a].second+vec[k][b].second;
				tree[rep[a]].pb(mp(rep[b],di));
				tree[rep[b]].pb(mp(rep[a],di));
			}
		}
	}
	while(q--){
		tree[0].clear();
		long long a,b;
		scanf("%lld%lld",&a,&b);
		long long l1=vec[a].size(),l2=vec[b].size();
		for(long long i=0;i<l1;i++){
			tree[0].pb(mp(vec[a][i].first,vec[a][i].second+tim[a]));
		}
		for(long long i=0;i<l2;i++){
			cld[vec[b][i].first]=1;
		}
		//check();
		printf("%lld\n",dfs(0,b,0,0)+tim[b]);
	}
}
