#include<bits/stdc++.h>
#define ll long long
#define up(_i,_l,_r) for(auto _i=(_l);_i<=(_r);_i++)
#define dn(_i,_r,_l) for(auto _i=(_r);_i>=(_l);_i--)
using namespace std;
const int N=2e6+5,M=2e5+5;
const int inf=0x3f3f3f3f,mod=1e9+7;
ll n,m;
ll a[N];
int l[N],r[N];
ll ans=0;
namespace n5000{
	ll dis[N],cnt[N];
	void bfs(int x){
		queue<int> q;
		q.push(x);
		while(q.size()){
			int u=q.front();q.pop();
			if(u==n) continue;
			up(i,u+1,r[u]){
				if(dis[i]>dis[u]+1){
					dis[i]=dis[u]+1;
					cnt[i]=cnt[u];
					q.push(i);
				}else if(dis[i]==dis[u]+1){
					cnt[i]+=cnt[u];
				}
			}
		}
	}
	void solve(){
		ans=0;
		up(x,1,n){
			if(r[x]>n||r[x]==x) continue;
			up(i,x+1,n) dis[i]=inf,cnt[i]=0;
			dis[x]=0,cnt[x]=1;
			bfs(x);
			up(i,1,n){
				if(cnt[i]==2) ans++;
			}
			dis[x]=cnt[x]=0;
		}
		printf("%lld\n",ans);
	}
}
namespace dc{
	void solve(){
		int d=a[2]-a[1];
		if(d>=m){
			puts("0");
			return;
		}
		if(r[1]>=n||r[1]<=2){
			puts("0");
			return;
		}
		printf("%d\n",n-2*(r[1]-1)+1);
//		if(n-2*(r[1]-1)+1==11) printf("debug: %d\n",n);
	}
}
void Main(int c){
	scanf("%lld%lld",&n,&m);
	up(i,1,n) scanf("%lld",a+i);
	if(n==1){
		puts("0");
		return;
	}
	up(i,1,n){
		int lt=i,rt=n;
		while(lt<rt){
			int mid=(lt+rt+1)>>1;
			if(a[mid]-a[i]<=m) lt=mid;
			else rt=mid-1;
		}
		r[i]=lt;
	}
	if(c<=10){
		n5000::solve();
		return;
	}
	if(c==11||c==12){
		dc::solve();
		return;
	} 
}
/*
我怎么要写t3了？？？
题意：定义一次“飞行”表示从一个点跳到另一个点，且两点坐标差<=d
求点对(u,v)的个数，使得u经过最少次数的飞行到v的路径恰好两条
首先一个点能飞到的点是一个区间，而且这可以求
有两条最短路径这个条件很奇怪，考虑转化
首先四十分做法就是对每个点跑dij，用个最短路计数
不是dij也行，往后bfs 
这对我们略有启发，我们对于一个点只统计它右边的点即可
似乎不太会，先写个bfs 
暴力写完了，看特殊性质
先看等差数列。设公差为d
如果d>m，直接输出0
d=m即每个点只能跳到下一个 似乎也是0
d<m才是真正要考虑的情况。
首先可以确定，r[i+1]=r[i]+1，即所有点能跳到的区间长度相等 
找规律，设1最远能跳x步，则所有点往后跳2x-1步一定可以 
即1和2x可以配对，共有n-2x+1对 
11 1
15 5
2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
*/
signed main(){
	if(1){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	}
	int c,Test=1;
	scanf("%d%d",&c,&Test);
	while(Test--){
		Main(c);
	}
	return 0;
}
/*
迷惑行为大赏会有我吗
关注洛谷uid967841谢谢喵
大胆无畏 维新革命
光明磊落 反战国家
骑着日之丸印的二轮车
恶灵退散ICBM
骑行穿过环状线 东奔西走 不算什么
少年少女 战国无双 跟从着浮世浪
千本樱 夜空中飞散
你的声音 也传达不到啊
此处设宴 钢铁牢笼中
从那断头台上跳下来吧
三千世界 黄泉之暗
青蓝之空 遥向彼方
就以那光线枪击穿吧
*/

