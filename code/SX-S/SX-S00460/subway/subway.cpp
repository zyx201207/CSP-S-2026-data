#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
const int N1=5e5+5,N2=505;
int n,m,fw,q,a[N1],len[N2],d[N2][N2],dis[N2][N2],b[N2][N2];
vector<pii> op[N1],v[N2];
void dij(int x){
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push({0ll,x});
	d[x][x]=0;
	while (!pq.empty()){
		pii dx=pq.top();pq.pop();
		if (b[x][dx.se])continue;
		b[x][dx.se]=1;
		for (auto i:v[dx.se]){
			if (b[x][i.se]||dx.fi+i.fi>=d[x][i.se])continue;
			d[x][i.se]=dx.fi+i.fi;
			pii tx={d[x][i.se],i.se};
			pq.push(tx);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>fw>>n>>m>>fw>>q;
	for (int i=1;i<=m;i++)cin>>a[i];
	for (int i=1;i<=n;i++){
		cin>>len[i];
		for (int j=1;j<=len[i];j++){
			int x,y;
			cin>>x>>y;
			op[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	memset(d,0x3f,sizeof(d));
	for (int i=1;i<=m;i++){
		for (auto j:op[i]){
			for (auto k:op[i]){
				if (j.fi==k.fi)continue;
				dis[j.fi][k.fi]=min(dis[j.fi][k.fi],j.se+k.se);
				dis[k.fi][j.fi]=min(dis[k.fi][j.fi],j.se+k.se);
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (dis[i][j]>1e15)continue;
			v[i].push_back({dis[i][j],j});
		}
	}
	for (int i=1;i<=n;i++){
		dij(i);
//		for (int j=1;j<=n;j++)cout<<d[i][j]<<' ';
//		cout<<'\n';
	}
	while (q--){
		int x,y,ans=9e18;
		cin>>x>>y;
		for (auto i:op[x]){
			for (auto j:op[y]){
//				cout<<i.fi<<' '<<j.fi<<'\n';
				ans=min(ans,a[x]+a[y]+i.se+j.se+d[i.fi][j.fi]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
