#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=515;
const int M=5e5+15;
int c,n,m,d,q;
int t[M];
int k[N];
vector<pair<int,int>> a[N],b[M];
int dis[N][N];
void get_dis(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		for(auto pa:a[i]){
			int xa=pa.first,ya=pa.second;
			for(auto pb:b[xa]){
				int xb=pb.first,yb=pb.second;
				dis[xb][i]=dis[i][xb]=min(dis[i][xb],ya+yb);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			if(dis[i][k]==1e18) continue;
			for(int j=1;j<=n;j++){
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int query(int x,int y){
	int res=1e18;
	for(auto px:b[x]){
		int u=px.first,i=px.second;
		for(auto py:b[y]){
			int v=py.first,j=py.second;
			res=min(res,i+j+dis[u][v]);
		}
	}
	res+=t[x]+t[y];
	return res;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&t[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			a[i].push_back({x,y});
			b[x].push_back({i,y});
		}
	}
	get_dis();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		printf("%lld\n",query(x,y));
	}
	return 0;
} 
