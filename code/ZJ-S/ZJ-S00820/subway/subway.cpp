//80~92
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[502];
vector<int>t[502];
vector<int>a[502];
int dis[502][502];
vector<pair<int,int>>lines[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	// cerr<<m<<endl;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		t[i].resize(k[i]+2);
		a[i].resize(k[i]+2);
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&a[i][j]);
			scanf("%lld",&t[i][j]);
			lines[a[i][j]].push_back(make_pair(i,t[i][j]));
		}
	}
	memset(dis,0x1f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		// cerr<<"?"<<i<<" "<<lines[i].size()<<endl;
		if(lines[i].size()>=2){
			int num=lines[i].size();
			for(int iu=0;iu<num;iu++){
				for(int iv=iu+1;iv<num;iv++){
					int u=lines[i][iu].first;
					int v=lines[i][iv].first;
					int w=lines[i][iu].second+lines[i][iv].second;
					// cerr<<"+"<<u<<" "<<v<<" "<<w<<endl;
					dis[u][v]=min(dis[u][v],w);
					dis[v][u]=dis[u][v];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				if(dis[u][v]>dis[u][i]+dis[i][v]){
					dis[u][v]=dis[u][i]+dis[i][v];
				}
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		if(dis[i][j]<1000){
	// 			cerr<<dis[i][j]<<"\t";
	// 		}
	// 		else{
	// 			cerr<<"inf\t";
	// 		}
	// 	}
	// 	cerr<<endl;
	// }
	for(int _=1;_<=q;_++){
		int u,v,ans=dis[0][0];
		scanf("%lld%lld",&u,&v);
		for(auto i:lines[u]){
			for(auto j:lines[v]){
				ans=min(ans,i.second+j.second+dis[i.first][j.first]);
			}
		}
		ans+=w[u]+w[v];
		printf("%lld\n",ans);
	}
	return 0;
}