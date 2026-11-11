#include<bits/stdc++.h>
#define pb emplace_back
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=510,M=5e5+10,K=1010;
int c,n,m,d,q,w[M],a[M],cnt,dis[K][K];
vector<pii> v[M<<1];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int i=1,l;i<=m;i++){
		cin>>l;
		for(int j=1,x,tim;j<=l;j++){
			cin>>x>>tim;
//			v[x].pb(++cnt,tim);
//			v[cnt].pb(x,tim);
			cnt++;
			dis[cnt][x]=dis[x][cnt]=tim;
			a[j]=cnt;
		}
		for(int j=2;j<=l;j++){
//			v[a[j]].pb(a[j-1],0);
//			v[a[j-1]].pb(a[j],0);
			dis[a[j]][a[j-1]]=dis[a[j-1]][a[j]]=0;
		}
	}
//		cout<<i<<":";
//		for(auto [j,t]:v[i]){
//			cout<<j<<" "<<t<<endl;
//		}
//		cout<<"==="<<endl;
//		v[i].clear();
//	}
//	cout<<"======"<<endl;
	for(int k=1;k<=cnt;k++){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
/*
score 32 pts
time 132 min

注意这题n,m互换了！！！
（以下n,m对应原题目的m,n）
我头文件模板打错了两次，请输入文本
感觉太像去年T2了，瞪一下数据范围
666 d<=20,m<=500，那没事了，不对这啥猎奇数据范围
不是好诡异啊这个题
666咋考四个小时，我以为跟J一样是三个半小时呢
注意到这个站台个数最多nd=1e7个
不是这么多我建你吗的图
哦不对啊不是\sum ki+n=6e5个点吗，傻逼了。
首先从地铁口走到站厅的花费是一定的，所以只要考虑两点之间如何最短就行了。
可以把站厅到站台的时间转化为站厅和站台间的边权，然后地铁线就是把几个点连相互连起来，边权为0
恩对了，这样图就建出来了
然后呢？q次询问怎么处理
这咋这么诡异，我要睡觉了
睡觉完毕，睡了30min
不是这个标点太不友好了/fn/fn/fn
OK也是终于搞好了。
额然后怎么快速求两点之间的最短路？
ki<=1000还可以用floyd，虽然说很卡
对于两个站厅，如果他们都能从地铁a->地铁b，那就选总花费小的那个一定优，那就可以把大的扔了
那就变成了说一堆地铁线，然后用一些站厅连接若干条线
kruskal重构树？？？
手玩一下样例感觉最小生成树很对，尝试一下
然后就可以dep+lca了/hanx
哦对注意到这场空间也是1024MiB所以你的空间并不会炸缸
坏了坏了坏了我钦定失败了，大样例没过
我靠确实最小生成树显然不对
那我只能暴力dijkstra了/kel
算了我要大力floyd，floyd还是太强了/bx
图上任意两点最短路到底怎么做/ll/ll/ll
哦注意到这个特殊性质B有32pts，尝试拿一下
注意到B等价于给你一坨集合，每次可以花费k=2T的代价使得穿梭到同集合的任意一个另外的元素，问从x->y的代价
也就是问你最少几次可以从x穿梭到y
把所有的站台都和对应的地铁编号连边，\sum ki+n
那怎么快速查询呢？
感觉还是不会，打个T3T4暴力玩玩就得了

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/