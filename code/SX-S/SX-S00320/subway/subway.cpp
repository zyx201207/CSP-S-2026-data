#include<bits/stdc++.h>
	
using namespace std;
const int N=5e5+10;
const int M=505;
int c,n,m,d,qry;
long long w[N];
long long f[M][M];
long long ans;
vector<pair<int,int> > e[N];
void sol(){
	cin>>c>>n>>m>>d>>qry;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,b;
			scanf("%d%d",&a,&b);
			e[a].push_back({i,b});
		}
	}
	for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		if(e[i].size()>=2){
			for(auto g1:e[i]){
				for(auto g2:e[i]){
					int u=g1.first,v=g2.first;
					if(v>u) break;
					long long w1=g1.second,w2=g2.second;
					f[u][v]=min(f[u][v],w1+w2);
					f[v][u]=min(f[v][u],w1+w2);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=qry;i++){
		int s,t;ans=1e18;
		scanf("%d%d",&s,&t);
		for(auto p:e[s]){
			for(auto q:e[t]){
				int u=p.first,v=q.first;
				long long w1=p.second,w2=q.second;
				ans=min(ans,w[s]+w[t]+f[u][v]+w1+w2);
			}
		}
		printf("%lld\n",ans);
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t=1;
	while(t--) sol();
	return 0;
}
//15:31:29 know 32
//15:39:00 unknown "正确性" solution
//15:59:34 我的天啊，我做出来了，我做到了
//16:20:00 时间差一点过，我不知道怎么优化了。CCF测评机一定要发力啊，我喜欢你