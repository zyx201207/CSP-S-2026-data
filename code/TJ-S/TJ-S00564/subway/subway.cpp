#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500001],outs[500001];
long long val[501][501],ans[501][501],sum;
vector<array<long long,2>> edge[500505],edges[5001];
void dij(int x){
	priority_queue<array<long long,2>> q;
	q.push({0,x});
	ans[x][x] = 0;
	while(!q.empty()){
		auto y = q.top();
		q.pop();
		if(y[0] != -ans[x][y[1]]){
			continue;
		}for(auto z:edges[y[1]]){
			if(ans[x][z[0]] > z[1]+ans[x][y[1]]){
				ans[x][z[0]] = z[1]+ans[x][y[1]];
				q.push({(-ans[x][z[0]]),z[0]});
				sum++;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%lld",&w[i]);
	}for(int i = 1;i <= n;i++){
		scanf("%lld",&k[i]);
		for(int j = 1;j <= k[i];j++){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			edge[x].push_back({m+i,y});
		}
	}for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			val[i][j] = 1ll<<60;
			ans[i][j]= 1ll<<60;

		}
	}
	for(int i = 1;i <= m;i++){
		int len = edge[i].size();
		for(int j = 0;j < len;j++){
			for(int k = j+1;k < len;k++){
				long long x = edge[i][j][0]-m,y = edge[i][j][1];
				long long xx = edge[i][k][0]-m,yy = edge[i][k][1];
				if(val[xx][x] > y+yy){
					val[xx][x] = val[x][xx] = y+yy;
				}
			}
		}
	}for(int i = 1;i <= n;i++){
		for(int j = i+1;j <=n;j++){
			if(val[i][j] != 1ll<<60){
				edges[i].push_back({j,val[i][j]});
				edges[j].push_back({i,val[i][j]});

			}
		}
	}for(int i = 1;i <= n;i++){
		dij(i);
	}for(int i = 1;i <= q;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long out = 1ll<<60;
		for(auto u:edge[x]){
			for(auto v:edge[y]){
				long long x = u[0]-m,y = u[1];
				long long xx = v[0]-m,yy = v[1];
				out = min(out,y+yy+ans[x][xx]);

			}
		}printf("%lld\n",out+w[x]+w[y]);
	}
}/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2*/
