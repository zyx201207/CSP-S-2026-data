#include<bits/stdc++.h>
using namespace std;

struct node {
	int to;
	long long d;
};

struct station {
	int a;
	long long t;
};

station s[505];
node g[500005][44];
int c, n, m, d, q, point[500005], k, x, y, cur;
long long w[500005], dis[500005], ans[1004][1004];
bool vis[500005];

void buildg(int k) {
	for(int i=1;i<=k;i++) {
		for(int j=i+1;j<=k;j++) {
			g[s[i].a][++point[s[i].a]].to=s[j].a;
			g[s[j].a][++point[s[j].a]].to=s[i].a;
			g[s[i].a][point[s[i].a]].d=s[i].t+s[j].t;
			g[s[j].a][point[s[j].a]].d=s[i].t+s[j].t;
		}
	}
}

long long solve(int x, int y) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	dis[x]=0;
	cur=x;
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=point[cur];j++) 
			dis[g[cur][j].to]=min(dis[cur]+g[cur][j].d, dis[g[cur][j].to]);
		vis[cur]=1;
		cur=500002;
		for(int j=1;j<=m;j++) {
			if(vis[j]) continue;
			if(dis[j]<dis[cur]) cur=j;
		}
	}
	
	if(c<=11) {
		for(int i=1;i<=m;i++) ans[x][i]=dis[i];
	}
	
	return dis[y];
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k;
		for(int j=1;j<=k;j++) cin>>s[j].a>>s[j].t;
		buildg(k);
	}
//	for(int i=1;i<=m;i++) {
//		for(int j=1;j<=point[i];j++) cout<<i<<' '<<g[i][j].to<<' '<<g[i][j].d<<endl;
//		cout<<endl;
//	}
	
	if(c<=11) {
		for(int i=1;i<=m;i++) solve(i, 1);
		for(int i=1;i<=q;i++) {
			cin>>x>>y;
			cout<<1ll*w[x]+1ll*w[y]+ans[x][y]<<endl;
		}
		fclose(stdin);
		return 0;
	}
	for(int i=1;i<=q;i++) {
		cin>>x>>y;
		cout<<1ll*w[x]+1ll*w[y]+solve(x, y)<<endl;
	}
	
	fclose(stdin);
	return 0;
}
