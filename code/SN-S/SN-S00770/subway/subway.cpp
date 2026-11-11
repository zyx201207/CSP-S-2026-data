#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const int L=500+10;
const ll inf=(ll)4e18;

int c,n,m,d,q;
vector<pair<int,int>> sta[N];
ll w[N],D[L][L];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			sta[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			D[i][j]=(i==j?0:inf);
		}
	}
	for(int v=1;v<=m;v++){
		for(size_t x=0;x<sta[v].size();x++){
			for(size_t y=x+1;y<sta[v].size();y++){
				int i=sta[v][x].first,j=sta[v][y].first;
				ll val=(ll)sta[v][x].second+sta[v][y].second;
				if(val<D[i][j])D[i][j]=D[j][i]=val;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(D[i][k]!=inf){
				for(int j=1;j<=n;j++){
					if(D[i][k]+D[k][j]<D[i][j]){
						D[i][j]=D[i][k]+D[k][j];
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll best=inf;
		for(auto& i:sta[x]){
			for(auto& j:sta[y]){
				best=min(best,(ll)i.second+D[i.first][j.first]+j.second);
			}
		}
		printf("%lld\n",w[x]+w[y]+best);
	}
	return 0;
}
