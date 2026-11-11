#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q,w[500001],k[501];
short e[500001][21];
int z[500001][21];
char cnt[500001];
vector<int>a[501],t[501];
ll dis[501][501];
bool vis[501];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int i,j,p;
	for(i=1;i<=m;i++)cin>>w[i];
	int x,y;
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++){
			cin>>x>>y;
//			e[x].push_back(make_pair(i,y));
			e[x][++cnt[x]]=i;
			z[x][cnt[x]]=y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(i=1;i<=n;i++){
		dis[i][i]=0;
		for(j=0;j<k[i];j++){
//			for(auto l:e[a[i][j]]){
			for(p=1;p<=cnt[a[i][j]];p++){
				dis[i][e[a[i][j]][p]]=min(dis[i][e[a[i][j]][p]],(ll)t[i][j]+z[a[i][j]][p]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cerr<<dis[i][j]<<" ";cerr<<endl;
//	}
	ll minn,now,l;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)vis[j]=0;
		vis[i]=1;
		for(j=1;j<n;j++){
			minn=1145141919810;
			for(p=1;p<=n;p++){
				if(vis[p])continue;
				if(dis[i][p]<minn){
					minn=dis[i][p];
					now=p;
				}
			}
			vis[now]=1;
			l=dis[i][now];
			for(p=1;p<=n;p++){
				dis[i][p]=min(dis[i][p],l+dis[now][p]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cerr<<dis[i][j]<<" ";cerr<<endl;
//	}
	ll ans;
	while(q--){
		cin>>x>>y;
		ans=1145141919810;
//		for(auto u:e[x]){
		for(i=1;i<=cnt[x];i++){
//			for(auto v:e[y]){
			for(j=1;j<=cnt[y];j++){
				ans=min(ans,z[x][i]+z[y][j]+dis[e[x][i]][e[y][j]]);
			}
		}
		cout<<w[x]+w[y]+ans<<endl;
	}
	return 0;
}
//Please give me 100pts!I love CCF!
//14:59 一个城市有 5e5 个地铁站？
//15:00 这是 O(md^2) 的预处理？还是说 O(dsum_k)？似乎是后者。
//15:17 O(n^3) 预处理所有地铁线路间的最短换乘时间，然后 O(d^2) 处理每个询问。有点极限且容易被卡。
//15:18 竟然现在才有老师收电子设备！
//15:20 笑点解析：我考前(12:44)还在想要不要复习最短路。
//15:24 这道 T2 也就绿吧？这是 CSP-S 的水准？？
//15:29 99!****!SPFA 不会写了！
//15:33 尝(wang)试(tu)写 Dijkstra。
//15:39 学会 Dijkstra 了！（应该是 Dijkstra 吧）
//15:42 写了一遍。
//15:44 答案都对但 T 了两个点。（就差<100ms）
//15:46 去写快读。
//15:54 快读写炸了。
//16:10 破案了。决速步是第 22 行的 cin>>x>>y;！
//16:16 等等，还有第 5 行的 vector<pair<int,int> >e[500001];！
//16:17 难道我要相信 CCF 少爷机？
//16:25 99!把 vector 拆成了两个二维数组。终于在 950ms 以内了。但是似乎出了点问题。
//16:30 ****!问题出在范围不够。改回去之后只优化了 ~40ms。
//16:31 算了吧。相信 CCF 少爷机。Ice 如果你能让我 100pts 的话我请你吃饭。