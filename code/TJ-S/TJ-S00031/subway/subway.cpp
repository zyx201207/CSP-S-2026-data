#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int C,n,m,D,Q,a,x,y,l,w[500001],e[501][500001],d[501][501],c[500001][21];
long long t,s,v[501];
struct N{
	int l;
	long long t;
};
queue<N> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&D,&Q);
	for(int i = 1;i <= m;i++){
		scanf("%d",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&e[i][0]);
		for(int j = 1;j <= e[i][0];j++){
			scanf("%d%d",&a,&e[i][j]);
			c[a][++c[a][0]] = i;
		}
	}
	memset(d,0x7f,sizeof(d));
	for(int i = 1;i <= m;i++){
		for(int j = 1;j < c[i][0];j++){
			for(int k = j + 1;k <= c[i][0];k++){
				if(e[j][i] && e[k][i]){
					d[j][i] = d[i][j] = min(d[i][j],e[j][i] + e[k][i]);
				}
			}
		}
	}
	while(Q--){
		scanf("%d%d",&x,&y);
		while(!q.empty()) q.pop();
		for(int i = 1;i <= c[x][0];i++){
			q.push({i,t + e[l][i]});
		}
		memset(v,0,sizeof(v));
		s = 0x7f7f7f7f7f7f7f7f;
		while(!q.empty()){
			l = q.front().l;
			t = q.front().t;
			v[l] = t;
			q.pop();
			for(int i = 1;i <= c[y][0];i++){
				if(c[y][i] == l){
					s = min(s,t + e[l][y]);
					break;
				}
			}
			for(int i = 1;i <= n;i++){
				if(d[l][i] && (!v[i] || v[i] > t + d[l][i])){
					q.push({i,t + d[l][i]});
				}
			}
		}
		printf("%d\n",s + w[x] + w[y]);
	}
	return 0;
}
