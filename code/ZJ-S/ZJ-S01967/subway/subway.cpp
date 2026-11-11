#include<bits/stdc++.h>
#include<vector>
#include<queue>
#define rep(i,b,e) for(int i=(b);i<=(e);++i)
#define _rep(i,b,e) for(int i=(b);i<(e);++i)
using namespace std;
const int N=510,M=5e5+10;
int n,m,d,q,w[M],k[N];
vector<int>h[N],a[N],t[N];

long long f[N][N];

int x,y;
void floyd(void) {
	rep(i,1,n) f[i][i]=0;
	rep(i,1,n) {
		rep(j,1,n) {
			rep(k,1,n) {
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main() {
	int ta,tb,tc;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%*d%d%d%d%d",&n,&m,&d,&q);
	rep(i,1,m) scanf("%d",&w[i]);
	rep(i,1,n) {
		scanf("%d",&k[i]);
		a[i].push_back(0),t[i].push_back(0);
		rep(j,1,k[i]) t[i].push_back(0);
		rep(j,1,k[i]) {
			scanf("%d%d",&ta,&tb);
			a[i].push_back(ta),t[i][a[i][j]]=tb;
//			scanf("%d%d",&a[i][j],&t[i][j]);
			h[a[i][j]].push_back(i);//记录站点i被那些线路经过 
		}
	}
	int l;
//	printf("EOF");
	memset(f,0x3f,sizeof(f));
	rep(i,1,n) {//遍历换乘点，准备缩点 
		if(h[i].size()>1) {//如果是换乘点 
			//该站从线路u->v的成本为t[u][i]+t[v][i]，即缩点后节点u->v的双向边权值为t[u][i]+t[v][i] 
			//some action...
			l=h[i].size();
			_rep(j,0,l) {
				_rep(k,j+1,l) {
					int u=h[i][j],v=h[i][k];
					f[v][u]=f[u][v]=min(f[u][v],t[u][i]*1ll+t[v][i]);
//					g[u].push_back({v,t[u][i]+t[v][i]}),
//					g[v].push_back({u,t[u][i]+t[v][i]});
				}
			}
//	printf("EOF");
		}
	}
	floyd();
	long long ans;
//	printf("t:\n");
//	rep(i,1,n) {
//		rep(j,1,k[i]) {
//			printf("%d ",t[i][j]);
//		}
//		printf("\n");
//	}
//	printf("f:\n");
//	rep(i,1,n) {rep(j,1,n) printf("%lld ",f[i][j]);printf("\n");}
	while(q--) {
		scanf("%d%d",&x,&y),ans=(long long)1e17;
		for(int u:h[x]) for(int v:h[y]) ans=min(ans,f[u][v]+t[u][x]+t[v][y])/*,printf("  %lld\n",f[u][v])*/;
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
//看懂题目都用了30min，我已经没救了qwq
//15:52 知道自己没救了，已经打算开始写考场时的大逝记了qwq
//solution?
//缩点，将每条线路缩成一个点，第i条线路到
//不对，若两条线路中有两个换乘点呢。。
//缩点依旧，不过权值为两个换乘点换乘所需的较小值。不对，是不是可以不用管。。。 
//继续 
//如何找到换乘点..
//用vector 

//...有坑，ki计数大小上限是按总和计算的，单个不知，要么开vector，要么类链式前向星(但我不会a) ，不能直接数组qwq 

//什么，16:40了。。。 only leave 1h50min

//但是但是，由于问题量过大，会T的。。。我。。。。。。。T_T 
//还有若是换乘点里线路太多，建图时边数会爆炸a
//于是乎,某于16:49发现自己的疑似假了qwq 
//17:07 :不管了... 
//17:13 等等,n<=500是不是可以直接写floyd啊,估算一下，时间复杂度疑似降了，好耶 
//17:15 权衡是否开long long,ti<=1e9，得开.. 
//17:20 突然发现输入都没写完。。 (划掉) 
//17:26 我输出怎么不见了aaaaaaaaaaaaaaaaaaa 
//17:29 Process exited after 0.1808 seconds with return value 3221225477哪里给我炸了a 
//only leave 1h..................
//17:36 有输出了，但答案是错的.........
//17:43 去上了个厕所。。 
//17:48 样例1的一个数据对了耶 
//17:50 广播突然说T2什么什么的，但没听清qwq 
//17:57 突然发现例1给出解释里公式计算出结果跟他给出的结果不同。。刚刚广播是不是说这个，那去钻研例2吧 
//18:06 脑子已炸 
//18:14 找到问题了，好耶 
//等等，只有15min了... 
//18:18 发现是t数组理解错了。。。时间来不及了，我...
//18:20 发现T1刚好520字节,4.00KB 
//18:27 疑似对了，好耶，再见^^ 
