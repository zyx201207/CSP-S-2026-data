#include<bits/stdc++.h>
#define ll long long
#define up(_i,_l,_r) for(auto _i=(_l);_i<=(_r);_i++)
#define dn(_i,_r,_l) for(auto _i=(_r);_i>=(_l);_i--)
using namespace std;
const int N=5e5+5,M=505;
const ll inf=0x3f3f3f3f3f3f3f3fll,mod=1e9+7;
int c,n,m,d,q;
ll w[N];
vector<pair<ll,ll>> p[N];
ll G[M][M]; 
void Main(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	up(i,1,m) scanf("%lld",w+i);
	up(i,1,n){
		int x;scanf("%d",&x);
		while(x--){
			ll v,t;scanf("%lld%lld",&v,&t);
			p[v].push_back({i,t});
		}
	}
	memset(G,0x3f,sizeof G);
	up(i,1,n) G[i][i]=0;
	up(x,1,m){
		up(i,0,p[x].size()-1){
			up(j,0,i-1){
				int u=p[x][i].first,v=p[x][j].first;
				G[u][v]=G[v][u]=min(G[u][v],
					p[x][i].second+p[x][j].second);
			}
		}
	}
	up(k,1,n){
		up(i,1,n){
			up(j,1,n){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
//	up(i,1,n){
//		up(j,1,n) printf("%lld ",G[i][j]);puts("");
//	}
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		ll ans=inf;
		up(i,0,p[x].size()-1){
			up(j,0,p[y].size()-1){
				int u=p[x][i].first,v=p[y][j].first;
//				printf("debug: %d %d\n",u,v);
				ans=min(ans,G[u][v]+p[x][i].second+p[y][j].second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
}
/*
T2题意：给出一个铁路网，q组询问，每次问从u到v，
地铁口到站厅+进入路线+换乘路线+离开路线+站厅到地铁口的最短时间
数据范围挺复杂的：线路500个，站口有5e5个，
每个站口最多有20条线路，1e5次询问 

首先地铁口和站厅的时间是来搞笑的，最后加上w[u]+w[v]就行
这个20看着就挺奇怪，500也有点过小了，5e5又太大
感觉从数据范围下手是对的，起码不能对站口建点 
我有一个猜想，对路线建点，路线有重复站台就建边
这样点500个，边不到500^2=250000 感觉挺对，而且还是floyd 
先看特殊性质吧
A：每条线路最多经过两个地铁站 这意味着线路只能连接俩站口
那么这条线路只会和40条线路相连，边是20000，这是想让你用dij？
B好像就是个不用判重边的东西，不管了

那么正解绝对就是对路线建点，有两条路线有重复经过就连边
话说这个地铁是单向还是双向的？似乎没说？要不我先写个双向的 
这个建图复杂度似乎上界是5e5*20*20的，2e8应该能跑 
wc我他妈过了！！！！！！！！！！ 
CEXE好闪，拜谢CEXE 
但是我最大点1.24s欸，能赢吗 
话说这输入量有点大吧，13M？
要不我搓个快读试试？算了最后吧 
*/
signed main(){
	if(1){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	}
	int Test=1;
//	scanf("%d",&Test);
	while(Test--){
		Main();
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

