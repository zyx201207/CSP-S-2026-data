#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int M=5e5+5,N=505,D=25;
int c,n,m,d,q;
int w[M];
vector<pair<int,int> > a[N];
vector<pair<int,int> > e[M];
pair<int,bool> vis[M];
long long dfs(int x,int y,int t){
	if(x==y)return 0;
	vis[x]={t,1};
	long long res=0x3f3f3f3f3f3f3f3f;
	for(auto v:e[x]){
		for(auto u:a[v.first]){
			if(vis[u.first].first==t&&vis[u.first].second){
				continue;
			}
			res=min(res,(long long)v.second+u.second+dfs(u.first,y,t));
			vis[u.first]={t,0};
		}
	}
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",w+i);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back({i,y});
			a[i].push_back({x,y});
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",dfs(x,y,q)+w[x]+w[y]);
	}
	return 0; 
}
