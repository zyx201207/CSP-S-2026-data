#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,d,q,w[N];
vector<pair<int,int>> v[N];
int f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _;cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;cin>>x>>t;
			v[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=1e18;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)v[i].size();j++){
			int x=v[i][j].first,t1=v[i][j].second;
			for(int k=j+1;k<(int)v[i].size();k++){
				int y=v[i][k].first,t2=v[i][k].second;
				f[x][y]=min(f[x][y],t1+t2);
				f[y][x]=min(f[y][x],t1+t2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			} 
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=w[x]+w[y],mn=1e18;
		for(int i=0;i<(int)v[x].size();i++){
			int l=v[x][i].first,t1=v[x][i].second;
			for(int j=0;j<(int)v[y].size();j++){
				int r=v[y][j].first,t2=v[y][j].second;
				mn=min(mn,t1+f[l][r]+t2);
			}
		}
		cout<<ans+mn<<'\n';
	}
	return 0;
}
/*
神秘最短路题，题面怎么这么长，先总结一下题意。 
n<=500,m<=∑k[i]<=5e5,d<=20,q<=1e5
地铁站 i 地铁口到站厅的边权为 w[i]
从站厅 j 走到第 i 条线路的边权为 t[i][j]
每个地铁站最多有 d<=20 条线路经过。
q<=1e5 次询问地铁站 i 到 j 的最短路，求全源最短路。
数据范围好奇怪，感觉可能是状压或者 Floyd。
先考虑暴力建图，把地铁站拆成地铁口,站厅，每个线路的入口三种。
那么最多有 dm 个点，∑k[i]+dm 条边。
每个询问暴力跑最短路有  30~40 分。
能不能考虑把线路视作点，先跑 Floyd 搞出最短路再来操作？
感觉可行，考虑先预处理出从线路 i 换乘到线路 j 所需最短时间。
建边考虑枚举每个站台，枚举经过该站台的所有换乘路线取边权和 min。
然后 Floyd 求出任意两条线路间最短路。
询问考虑枚举经过站台 x 的线路和经过 y 的线路，取拼接后最小值。
时间复杂度 O(n^3+md^2+qd^2)，2e8 有点极限，相信 CCF 少爷机。 
1h 通过 T1,T2，我今天咋这么牛？
算了，再卡卡 T2。 
*/