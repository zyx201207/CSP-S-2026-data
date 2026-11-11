#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;
int c,n,m,d,q;
ll f[510][510],b[510][510];
int w[500100];
vector<pair<int,int>> a[500100];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%d",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d",&k);
		for(;k--;){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x].push_back({i,y});
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)if(i != j){
			b[i][j] = f[i][j] = inf;
		}
	}
	for(int i = 1;i <= m;i++){
		int len = a[i].size();
		for(int j = 0;j < len;j++){
			for(int k = j + 1;k < len;k++){
				b[a[i][j].first][a[i][k].first] = min(b[a[i][j].first][a[i][k].first],1LL * a[i][j].second + a[i][k].second);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			f[i][j] = f[j][i] = min(b[i][j],b[j][i]);
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++)if(f[i][k] != inf && f[k][j] != inf){
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
/*	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}*/
	for(;q--;){
		int x,y;
		scanf("%d%d",&x,&y);
		ll mi = 1e18;
		for(auto r : a[x]){
			for(auto k : a[y]){
				mi = min(mi,0LL + r.second + k.second + f[r.first][k.first]);
			//	printf("%d %d\n",k.first,k.second);
			}
		}
	//	printf("%lld\n",mi);
		printf("%lld\n",0LL + w[x] + w[y] + mi);
	}
	return 0;
}