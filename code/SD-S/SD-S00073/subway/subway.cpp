//subway.cpp
/*
一定要注意理解好题意，看好变量名，不要出错！！！ 

发现所有的答案首尾都要加上：w[xr]+t[xr]+(...)+t[yr]+w[yr]，所以不妨对这些单独统计，然后就只需要考虑换乘的问题了 

-------------------

不妨把主点存为m个站台，那么我们可以通过加边来实现换乘的简化操作，然后需要处理好换乘之间的时间消耗

-------------------

考虑能否从题目的特殊之处找性质：
数据范围：
1.n很小，甚至支持O(n^3)的floyd，所以有可能是基于线路去考虑 
2.d也很小，只有20，意味着每个站点被经过的线路数量并不会很多，那么从这个站点换乘的可能情况最多就只有20*20=400种，可以暂时暴力存储

基于此，有了一个暴力思路，即以每个线路整体为一个大结点，然后去维护线路之间的转移关系
如果要换线路，那么只能通过换乘的方式，即寻找两个线路之间的公共站点，然后统计从“A线路的站台->站厅->B线路的站台”这一段的耗时
然后统计答案时只要枚举一下起点和终点所属的站点即可 

现在瓶颈在于如何快速寻找两个线路之间的公共站点？或者如何快速处理它们的贡献？
这时候d就派上用场了，由于经过同一个站点的线路个数不会超过20个，所以考虑直接对站点被经过的线路枚举

算一下时间复杂度（点数为n=500），建边先枚举两点n^2=2500，然后枚举其中一个的站点ki=5e5，再枚举这个站点被经过的线路d=20 
建边部分的复杂度为 O(n * max{ki} * d)，跑最短路用Floyd O(n^3)，询问时暴力枚举 O(d^2 * q) 
 
预期可以通过测试点第1~23的数据
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505, M=5e5+7;

//注意long long！！！！！！！！！！！！！！！！！！！！！！！！！！！ 

int c,n,m,d,q,k[N],w[M];
struct Node{
	int x; ll t; //经过的地铁站编号、到站厅的时间 
}; 
vector<Node> a[N]; 
unordered_map<int,ll> b[M]; // b[i][j]:站点i经过的线路中，j线路从站厅到站台的最短时间 有优化空间？
ll f[N][N]; 

void solve()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	/*
	1.输入
	2.枚举线路和线路之间i,j，然后找出i,j之间的公共点（枚举i经过的点，然后枚举每个点被经过的线路）
	3.计算经过公共点换乘线路的时间，保留所有时间中最短的那个，存储到Floyd中
	4.Floyd全源最短路
	5.处理询问，枚举经过两个站点的线路，求最小的f[i][j] 
	*/
	for(int i=1;i<=n;i++){
		cin>>k[i]; a[i].reserve(k[i]+5);
		for(int j=1;j<=k[i];j++){
			//需要存储：线路i经过了哪些点 和 i到对应点站厅的时间，每个点被经过的线路 和 点到线路的最短时间 
			int x; ll t; cin>>x>>t;
			a[i][j].x=x,a[i][j].t=t;
			if(!b[x].count(i) || b[x][i]>t) b[x][i]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=1e18;
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int p=1;p<=k[i];p++){ //i经过的点 
			for(auto it:b[a[i][p].x]){ //经过点p的线路
				int j=it.first;
				if(i==j) continue; 
				ll tim=a[i][p].t+it.second;
				if(f[i][j]>tim) f[i][j]=f[j][i]=tim;
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
		int x,y; cin>>x>>y;
		ll minn=1e18;
		for(auto i:b[x]){
			for(auto j:b[y]){
//				cerr<<i.first<<' '<<j.first<<' '<<i.second<<' '<<f[i.first][j.first]<<' '<<j.second<<' '<<f[i.first][j.first]+i.second+j.second<<'\n';
				minn=min(minn,f[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<minn+w[x]+w[y]<<'\n';
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

/*
0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6

Output:35
*/

//fc subway7.ans subway.out
