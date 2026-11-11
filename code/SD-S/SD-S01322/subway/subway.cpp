#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int N = 503,M = 5e5+5;
inline int read(){
	int s = 0;char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch))s = (s<<1)+(s<<3)+ch-'0',ch = getchar();
	return s;
}
int n,m,w[M];
ll dis[N][N];
vector<int> sid[M],st[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int tc = read();
	n = read();m = read();
	int d = read(),Q = read();
	for(int i = 1;i<=m;i++)w[i] = read();
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1,k,a,t;i<=n;i++){
		dis[i][i] = 0;
		k = read();
		while(k--){
			a = read();t = read();
			sid[a].eb(i);
			st[a].eb(t);
		}
	}
	for(int i = 1,u,v;i<=m;i++){
		for(int j = 0;j<(int)sid[i].size();j++)
			for(int k = 0;k<j;k++){
				u = sid[i][j];
				v = sid[i][k];
				dis[u][v] = dis[v][u] = min(dis[u][v],(ll)st[i][j]+st[i][k]);
			}
	}
	for(int p = 1;p<=n;p++){
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<i;j++)
				dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][p]+dis[p][j]);
	}
	ll ans;
	while(Q--){
		int u = read(),v = read();
		ans = 1LL<<60;
		for(int i = 0;i<(int)sid[u].size();i++)
			for(int j = 0;j<(int)sid[v].size();j++){
				ans = min(ans,st[u][i]+st[v][j]+dis[sid[u][i]][sid[v][j]]);
			}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}

