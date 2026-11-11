#include <bits/stdc++.h>

using namespace std;

int c, n, m, d, q;

int ndes;

struct Edge{
	int to;
	int w;
};

vector< vector<Edge> > g;

int dij(int x, int y){
	vector<bool> vis(ndes + 1, 0);
	vector<int> dis(ndes + 1, 0x3f3f3f3f);
	dis[x] = 0;
	
	for(int i=1; i<=ndes; i++){
		int mind=0x3f3f3f3f, mdid;
		for(int j=1; j<=ndes; j++){
			if(!vis[j] && dis[j] < mind){
				mind = dis[j];
				mdid = j;
			}
		}
		
		int l = g[mdid].size();
		for(int i=0; i<l; i++){
			if(!vis[g[mdid][i].to]){
				dis[g[mdid][i].to] = min(dis[g[mdid][i].to], dis[mdid] + g[mdid][i].w);
			}
			
		}
		
		vis[mdid] = true;
	}
	
	return dis[y];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

    cin>>c>>n>>m>>d>>q;
    
    ndes = 2 * m;
    
    g.resize(ndes + 1); //2 * m : gate & hall
    
    for(int i=1; i<=m; i++){
    	int w;
    	cin>>w;
    	
    	g[2 * i].push_back(Edge{2 * i - 1, w}); // 1, 3, 5, 7 2n-1 地铁口n
    	g[2 * i - 1].push_back(Edge{2 * i, w}); // 2, 4, 6, 8   2n 站台n
	}
	
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		
		vector<int> a(k + 1);
		vector<int> t(k + 1);
		
		for(int j=1; j<=k; j++){
			cin>>a[j]>>t[j];
			for(int l=j; l>=1; l--){
				// 和之前的本线路上所有站点双向连接
				g[2 * a[j]].push_back({2 * a[l], t[j] + t[l]});
				g[2 * a[l]].push_back({2 * a[j], t[l] + t[j]});
			}
		}
	}
	
	for(int i=1; i<=q; i++){
		int x, y;
		cin>>x>>y;
		
		int ans = dij(x * 2 - 1, y * 2 - 1);
		
		cout<<ans<<endl;
	}

	return 0;
}

/*

//freopen

什么叫输入 c 表示测试点编号
什么叫若 c=0 则这个点是样例

谢谢CCF喵 CCF我爱你喵
可惜我应该是用不上喵
这个题就是难看懂喵
应该是把图建对然后直接dijskra喵

不过我忘记djiskra怎么写了喵
只记得思路喵
试试喵

15:37

----------

样例一手画出来了
试试建图
没有负权应该就是dijskra
我也只会写到dij别的不会了
欸
“输入的第一行包含五个非负整数c, n, m, d, q，”
c, n, m, d ?

不考虑站台作为节点，直接链接站厅边权为两个到站台的时间之和
对于节点 n
若 n % 2 == 1 则 n 是 地铁口 (n+1) / 2 (直接除以二向下取整)
否则 n 是 站厅 n / 2

这样换乘处理不了但是
诶好像能处理
就是直接到站厅用时是两个到站台的时间

忘记优先队列怎么写了手写一个堆试试

---------
16:53
我在这里写堆干什么
手写的就是 O n^2
和不优化没区别

---------
17:00
拜了拜 kkksc03 和奶奶
样例一过了！！！
这么大一坨我可不想调

17：01
样例二过了！！！

17：04
3过了！4卡了！
不要紧，思路正确就已经超常发挥了！

17：05
5卡了！6卡了！
7就不测了！1MB的输入肯定过不了！

17:08
样例全超100KB了！不能写了！

*/