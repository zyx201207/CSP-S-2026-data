#include <bits/stdc++.h>  // RP++!
using namespace std;
const int N = 505,M = 4e5 + 2;
int c,n,m,d,q,ans = 0;
int flag[M];
int w[M];
vector<pair<int,int> > p[M];
int k[N];
int vis[N],visp[M];
vector<int> a[N],t[N];
//int idx = 0;
//int e[M],ww[M],ne[M],h[M];
//void add(int a,int b,int c){
//	e[idx] = b,ww[idx] = c,ne[idx] = h[a],h[a] = idx++;
//}
void dfs(int x,int y,int step){
	int l = p[x].size();
	for(int i = 0;i < l;i++){
		int line0 = p[x][i].first;
		if(vis[line0])
			continue;
		vis[line0] = 1;
		for(int j = 0;j < k[line0];j++){
			int point0 = a[line0][j],cost = 0;
			if(visp[point0])
				continue;
			for(int kk = 0;kk < k[line0];kk++){
				if(a[line0][kk] == point0){
					cost = t[line0][kk];
					break;
				}
			}
			if(point0 == y){
				ans = min(ans,step + p[x][i].second + cost);
				return;
			}
			if(!flag[point0])
				continue;
			visp[point0] = 1;
			dfs(point0,y,step + p[x][i].second + cost);
			visp[point0] = 0;
		}
		vis[line0] = 0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++){
		scanf("%d",&k[i]);
		for(int j = 1;j <= k[i];j++){
			int a_0,t_0;
			scanf("%d%d",&a_0,&t_0);
			a[i].push_back(a_0),t[i].push_back(t_0);
			p[a_0].push_back({i,t_0});
		}
	}
	for(int i = 1;i <= m;i++){
		if(p[i].size() >= 2)
			flag[i] = 1;
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		memset(visp,0,sizeof(visp));
		int x,y;
		scanf("%d%d",&x,&y);
		ans = 0x3f3f3f3f;
		dfs(x,y,0);
		visp[x] = 0;
		printf("%d\n",ans+w[x]+w[y]);
	}
	return 0;
}
