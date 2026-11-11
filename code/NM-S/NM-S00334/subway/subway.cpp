#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long k[510],w[500010],a[510][500010],t[500010][510],dst[500010][510];
vector<long long>v[500010][510],e[500010];
long long bfs(long long stt,long long stp){
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;j++){
			dst[i][j]=-1;
		}
	}
	deque<pair<long long,long long> >que;
	for(auto i:e[stt]){
		dst[stt][i]=t[stt][i];
		que.push_back({stt,i});
	}
	while(!que.empty()){
		auto x=que.front();
		que.pop_front();
		for(auto i:v[x.first][x.second]){
			if(dst[i][x.second]==-1||dst[i][x.second]>dst[x.first][x.second]){
				dst[i][x.second]=dst[x.first][x.second];
				que.push_front({i,x.second});
			}
		}
		for(auto i:e[x.first]){
			if(dst[x.first][i]==-1||dst[x.first][x.second]+t[x.first][x.second]+t[x.first][i]<dst[x.first][i]){
				dst[x.first][i]=dst[x.first][x.second]+t[x.first][x.second]+t[x.first][i];
				que.push_back({x.first,i});
			}
		}
	}
	long long mi=1e18+7;
	for(auto i:e[stp]){
		mi=min(mi,dst[stp][i]);
	}
	return w[stt]+w[stp]+mi;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(long long j=1;j<=k[i];j++){
			scanf("%d",&a[i][j]);
			e[a[i][j]].push_back(i);
			scanf("%d",&t[a[i][j]][i]);
		}
		for(long long j=1;j<=k[i];j++){
			if(j!=1){
				v[a[i][j]][i].push_back(a[i][j-1]);
			}
			if(j!=k[i]){
				v[a[i][j]][i].push_back(a[i][j+1]);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		long long stt,stp;
		scanf("%d%d",&stt,&stp);
		printf("%d\n",bfs(stt,stp));
	}
	return 0;
}

