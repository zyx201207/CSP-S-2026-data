#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=507,M=5e5+7;
int c,n,m,d,q;
int w[M];
long long dis[N][N];
struct node{
	int id;
	long long x;
};
vector<node>e[M];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=2e17;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k1;
		scanf("%d",&k1);
		for(int j=1;j<=k1;j++){
			int a,b;
			scanf("%d%d",&a,&b);
			e[a].push_back({i,b});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int k=0;k<e[i].size();k++){
				int l=e[i][j].id;
				long long lx=e[i][j].x;
				int r=e[i][k].id;
				long long rx=e[i][k].x;
				if(l!=r)dis[l][r]=lx+rx;
			}
		}
	}
	floyd(); 
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		long long ans=1e18;
		for(int j=0;j<e[l].size();j++){
			for(int k=0;k<e[r].size();k++){
				int a=e[l][j].id;
				long long lx=e[l][j].x;
				int b=e[r][k].id;
				long long rx=e[r][k].x;
				ans=min(ans,w[l]+w[r]+lx+rx+dis[a][b]); 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
