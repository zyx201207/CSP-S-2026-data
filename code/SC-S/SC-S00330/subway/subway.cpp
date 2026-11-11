#include<bits/stdc++.h>
using namespace std;
#define int long long 
//#define lowbit(x) ((x)&(-(x)))
#define pnt pair<int,int> 
bool MS;
int dis[505][505],a[1000001];
vector<pnt>g[1000001];
void solve(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,w;
			cin>>x>>w;
			g[x].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1e18;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(pnt u:g[i]){
			for(pnt v:g[i]){
				if(u.first==v.first)continue;
				dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int U,V;
		cin>>U>>V;
		int ans=1e18;
		for(pnt u:g[U]){
			for(pnt v:g[V]){
				ans=min(ans,dis[min(u.first,v.first)][max(u.first,v.first)]+u.second+v.second+a[U]+a[V]);
//				printf("%lld %lld %lld %lld %lld---\n",u.first,v.first,dis[u.first][v.first],u.second,v.second);
			}
		}
		cout<<ans<<"\n";
	}
}
bool MT;
signed main(){
//	system("fc /W subway.out subway7.ans");
//	return 0;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)solve();
//	cerr<<((&MS)-(&MT))/(1024.0*1024.0)<<" MB "<<clock()/1000.0<<"s Time";
}
/*
旁边小孩哥睡得好香啊
呼噜声好明显啊
我要睡着了
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/