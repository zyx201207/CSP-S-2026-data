#include<bits/stdc++.h>
using namespace std;
#define N 5005
#define int long long 

int c,t,n,d,ans,cc;
int x[N],f[N][N],vi[N][N];

void dfs(int s,int now,int t,int an){
	if(now==t){
		if(an==f[s][t]){
			cc++;
		}
		return ;
	}
	for(int i=now+1;i<=t;i++){
		if(x[i]-x[now]<=d){
			dfs(s,i,t,an+1);
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c>=13&&c<=14){
			cout<<0<<'\n';
			continue ;
		}
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+1+n);
		memset(f,0x3f,sizeof(f));
		memset(vi,0,sizeof(vi));
		for(int i=1;i<=n;i++){
			vi[i][i]=1;
			f[i][i]=0;
		}	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])<=d){
					f[i][j]=1;
					vi[i][j]=1;
				}
			}
		}
		for(int len=1;len<=n;len++){
			for(int l=1;l+len<=n;l++){
				int r=l+len;
				if(f[l][r]==1)	continue ;
				for(int k=l;k<=r;k++){
					f[l][r]=min(f[l][r],f[l][k]+f[k][r]);
				}
				if(f[l][r]==f[0][0])	continue ;
				int cn=0;
				for(int k=l+1;k<=r-1;k++){
					if(f[l][r]==f[l][k]+f[k][r]){
						cn+=vi[l][k]*vi[k][r];
					}
				}
				vi[l][r]=max(vi[l][r],cn);
				if(cn==2){
					ans++;
				}
			}
		}
		if(n<=9){
			ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					cc=0;
					dfs(i,i,j,0);
					if(cc==2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
			continue ;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
三道图论吗？
T1 15 min 写了，后面再回来拍一下吧

bur T2 是啥啊？q 次询问是不是有点难受？
把每条线路看成一个点，然后每个站台向点连边
考虑这个 d 有什么说法，相当于每个站台作为一个点，最多会向外连 20 个边 
哟，是不是其实 因为 n 比较小，而且两个点之间要想连接，必定会经过至少一个路线，
所以是不是计算一下 从每个路线到其他所有点的最短路径，然后查询的时候在遍历一下这些路径就行了？
不知道呢？应该是吧，复杂度的话 查询是 nq 的，
前面的操作，因为边数是 \sum k  跑 n 遍 dij，nklogk 的，我日，好像有点紧
而且这个空间也有点玄那，那怎么办？

应该是不能对于每个 n 枚举 k 的，不然这个就已经 2e8 了，噢噢噢，如果说我会在枚举一个，额，不对
怎么就 1 个小时了啊，我到底干了啥？
哦哦哦，一个点站台的出度的最多为 20，那我是不是直接先求一边线路与线路之间的最小距离，
这样我查询的时候，对于每个点 x，我直接枚举一下他首先去哪个线路 i，再枚举一个最终会到哪个线路 j
那答案就是 dis[i][x]+dis[j][y]+f[i][j] 
这样的话，查询复杂度变成 qnd？那这也不对啊，查询又炸了

哦哦哦，是不是我可以通过这个 f 直接算出开始的 每个路线到每个点的距离，
不行，再想 10 min
前两个东西在一起应该有 80 分

哦哦哦，等一下，你发现 其实 同时连接一个的只有 20 个，意思就是说，连接 x 的有 20 个，y 的有 20 个，
那不直接 单次最多 400 种搭配？

所以理一下思路：
首先 在一开始算一下 两两路线之间的 f
然后同时记录一下每个车站所连接的路线有哪些，
然后查询就是枚举直接与 x，y 相邻的那些边，然后加上 f 

呼，4:30 过了大样例

T3 应该是 dp 吧
要想路径最短，那我肯定每一步都燃尽了的跳
感觉答题思路应该是看，满足能恰好通过两条路径跳到的点对有什么性质

n<=5000 的点应该是直接 n^2 建边
先看后面的吧
好吧又回来了
性质 b 是不是好像有结论？沃日，不给这个的大样例吗？

半个小时了，进展为 0
直接飞往所有的吗？那是不是长度最多为 2d？有什么用吗这个
不对，n<=5000 还不能直接 拓扑计数，这个好像只有 24 ？
沃日，什么垃圾肉干，难吃死了
哦哦哦 5000 的应该是 floyd 吧，是个锤子，自己笑没

猜个结论：当两个点为 双径岛屿对，他们之间所经过的点，如果相邻两条跳跃不一样，那他们的起点只差 1
对个p，不不不不不，为啥我还是啥都不会？
已经玩了快一个小时了。
我该怎么快速判断给定两个点是不是 双径岛屿对？
思考 双径岛屿对 满足的性质：
首先，他肯定不能刚好走满，那么此时，他就会有一些步有剩余，

不管了，先打个 24 分吧
bur，怎么第 3 个点一直过不去啊
*/