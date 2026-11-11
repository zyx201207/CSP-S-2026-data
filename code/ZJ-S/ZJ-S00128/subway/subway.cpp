#include <bits/stdc++.h>
using namespace std;
struct station{
	int rail[21];
	int time[21];
	int tp=1;
}t[1005];
int c,n,m,d,q;
int w[1005];
int vis[1005];
vector<int> xl[505];
int ans[1005][1005];
struct tour{
	bool vis_xl[505];
	int t;
	int time;
	int lst;
};
void bfs(int st,int ed){
	queue<tour> q;
	tour k;
	memset(k.vis_xl,false,sizeof k.vis_xl);
	for(int i=1;i<=m;i++)vis[i]=INT_MAX;
	k.time=w[st],k.t=st,k.lst=INT_MAX;
	q.push(k);
	while(!q.empty()){
		tour tou=q.front();
		q.pop();
		if(tou.time>vis[tou.t])continue;
		vis[tou.t]=min(tou.time,vis[tou.t]);
		for(int i=1;i<=t[tou.t].tp;i++){
			int train=t[tou.t].rail[i];
			if(tou.vis_xl[train])continue;
			tou.vis_xl[train]=true;
			for(int j:xl[train]){
				if(j==tou.t)continue;
				tour ne;
				ne.lst=tou.t;
				ne.t=j;
				ne.time=tou.time+t[tou.t].time[i];
				for(int k=1;k<=t[j].tp;k++){
					if(t[j].rail[k]==train){
						ne.time+=t[j].time[k];
						break;
					}
				}
				for(int k=1;k<=n;k++)ne.vis_xl[k]=tou.vis_xl[k];
				q.push(ne);
			}
			tou.vis_xl[train]=false;
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=st){
			ans[st][i]=ans[i][st]=vis[i]+w[i];
		}
	}
	cout << vis[ed]+w[ed] << '\n';
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)ans[i][j]=INT_MAX;
		ans[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int xx,yy;
			cin >> xx >> yy;
			xl[i].push_back(xx);
			int tpp=t[xx].tp;
			t[xx].rail[tpp]=i,t[xx].time[tpp]=yy;
			t[xx].tp++;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		if(ans[x][y]!=INT_MAX)cout << ans[x][y] << '\n';
		else bfs(x,y);
	}
	return 0;
} 
//44!
