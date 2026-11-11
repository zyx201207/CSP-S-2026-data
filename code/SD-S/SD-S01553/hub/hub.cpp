#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,k;
vector<int> e[N];
int d[N];
namespace sub1{
	int f[4010][4010][2][3];
	int sz[4010];
	void dfs(int u,int fa){
		sz[u]+=sz[v];
		for(int i=0;i<=min(sz[u],k);i++){
			for(int j=0;j<2;j++){
				for(int l=0;l<3;l++){
					f[u][i][j][l]=N;
				}
			}
		}
		f[u][0][0][0]=0;
		for(auto v:e[u])if(v!=fa){
			dfs(v,u);
			sz[u]+=sz[v];
			for(int i=1;i<=min(sz[v],n);i++){
				for(int j=0;j<2;j++){
					for(int k=0;k<3;k++){
						for(int x=sz[u];x>=sz[v];x--){
							f[u][0][1]=min(f[u][0][1],max(f[u][0][0],min(f[v][0][1],f[v][0][1])));
						}
					}
				}
			}
		}
	}
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		d[i]=0;
	}
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
		d[x]++;
		d[y]++;
	}
	if(n==2){
		printf("0\n");
		return ;
	}
	int rt=1;
	for(int i=1;i<=n;i++){
		if(d[i]>1){
			rt=i;
			break;
		}
	}
	if(n<=4000){
		sub1::dfs(rt,0);
		printf("%d\n",min({f[1][k][0][0],f[1][k][0][1],f[1][k][1][0],f[1][k][1][1]}));
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}
