#include<bits/stdc++.h>
using namespace std;
using ll=long long;
namespace Solver_T4{
	int dis[1005][1005];
	int uu[2000005],vv[2000005];
	void Elaina(){
		int n,k;
		cin>>n>>k;
		bool flag=1;
		if(n%2==0)flag=0;
		if(n<=1000){
			memset(dis,0x3f,sizeof(dis));
			for(int i=1;i<=n;i++)dis[i][i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			uu[i]=u,vv[i]=v;
			if(n<=1000)dis[u][v]=dis[v][u]=1;
			if(i<=n/2&&(u!=i||v!=i+1))flag=0;
			if(i>n/2&&(u!=i-n/2||v!=i+1))flag=0;
		}
		if(n<=100){
			for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
		if(k==n){
			cout<<0<<'\n';
			return;
		}
		if(n<=16){
			int ans=114514;
			for(int i=0;i<(1<<n);i++){
				if(__builtin_popcount(i)!=k)continue;
				int c=k;
				for(int j=1;j<n;j++){
					int u=uu[j],v=vv[j];
					if((i&(1<<u-1))&&(i&(1<<v-1)))c--;
				}
				if(c>2)continue;
				int z=0;
				for(int j=1;j<=n;j++){
					int w=114514;
					for(int k=1;k<=n;k++)if(i&(1<<k-1))w=min(w,dis[j][k]);
					z=max(z,w);
				}
				ans=min(ans,z);
			}
			cout<<ans<<'\n';
			return;
		} 
		if(flag){
			if(k>=n/2){
				cout<<1<<'\n';
				return;
			}
			cout<<(n/2-k+3)/4+1<<'\n';
			return;
		}
		if(n<=1000&&k==2){
			if(n>100)for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			int ans=114514;
			for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
				int z=0;
				for(int k=1;k<=n;k++)z=max(z,min(dis[k][i],dis[k][j]));
				ans=min(ans,z);
			}
			cout<<ans<<'\n';
			return;
		}
	}
	void Recall(){
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		ios::sync_with_stdio(0);cin.tie(0);
		int _id,T;
		cin>>_id>>T;
		while(T--){
			Elaina();
		} 
	}
}
int main(){
	Solver_T4::Recall();
}
/*
Done T1 at 14:51.
Done T2 at 15:13.
Done T3 at 16:54?

T4首先会15分的暴力

这个T4是神秘树上最优化
遇到最优化题，第一件事首先想二分答案

15分暴力 is ez
30分是树上dp吗？
k=2怎么做？
O(nk)有65分，怎么做？ 
感觉会一个差不多有35的树上dp
意思就是维护，当前还能选几个，当前还能选几个连通块，这个节点选不选，这个节点离最近的基地的距离
但是转移有问题啊
比如这种情况
1-2 2-3 2-4 当我们在3设基地，那么，4距离最近的基地3的距离是2

但是我们当在1设基地的时候，没办法计算4距离1的距离
那么，当k=2时，咋做？
k=1显然放在直径中点
思考一下A性质
A性质就是树是一条区
1-2-3-4-5
1-6
2-7
3-8
4-9
这种
那么A性质是否有闭式解
A性质如果k>=n/2+1，那么显然答案是1 
如果k=n/2呢？那么链上放不满，但是5可以不放，这样答案是1
一般情况，我们最好放在链的1/4等分点和3/4等分点
k=2的情况就是，我们必须放在链的1/4等分点和3/4等分点
就如果，1-2-3-4-5-6-7-8-9-10-11，1-10都挂一个点
那么我们放在3和9？这样是4
那么我们放在4和8？这样也是4
我们放在3和8？这样是3
这个11号点我们可以忽略，只要不往上面放点，则是不需要的
所以就是1-10这条链，每个地方挂一个点
挂点就相当于答案加1啊

然后暴力和A性质写完了
看看有没有多项式解法
感觉我会9倍常数n^3 k
这个一个点都过不了

感觉，一般情况不会就是k=2情况的扩展吧
先选定两个重心，然后往外延伸

额，感觉树上dp细节非常多，写不了啊
而且我想的多项式维护方法，感觉也是不太行的
因为一个点，去两个中心，是需要计算两个中心的距离，不能随便维护

k=2怎么做？
 
感觉肯定要从k=2开始想

感觉，必须想出来k=2是怎么做啊

点7感觉也只会3方啊

哦我们是不是可以预处理两点之间的距离

预处理了距离没用啊，考虑每次问距离只能一个一个统计啊

总不能是bitset追忆过去吧

3e9，感觉就过不了
试试吧，最后5分钟了 
*/

/*
Luogu: 1820333

我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC

只要AK就能去WC！

还有机会AK吗？？？


强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 
强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 
强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 
强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 
强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 
强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 
强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 
强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 
强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 
强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 
强烈推荐 Riven Pilgrimage by rejection & Supire feat.eili 

[Ticket to NOIP2026] [√]
[Ticket to WC2027] [?]

这场比赛的难度，是，橙绿青紫？

very csp-s2024

这意味着，我们只需要在T4多打点暴力（24分）就可以获得冬令营的门票

 

都高一了都没有冬令营去我真是区了 

发现，如果我不挂分，则我能够拿到惊人的325分
已完成今日325大学习

算了，如果我挂分，我就声称是因为我没有虚拟机调试环境才挂的分
反正我已经高一了，只要有分就能去NOIP
冬令营是啥，不知道啊

Part of my heart was left behind the way
I remember the destination of the rain
Ask myself what atonement means
Why not take me away to heaven 

是这样唱的吗，我都忘了
应该不是destination

恐怖！DEINOS PHAINEIN来袭

压缩包密码竟然有1225 

*你找不到你的压缩包了 

我是区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区区


Execution Execution Execution Execution Execution Execution Execution Execution
EXECUTION EXECUTION EXECUTION EXECUTION 1 2 3 4 5 6（忘了哪六种语言了） EXECUTION

//freopen("hub.in","r",stdin);
//freopen("hub.out","w",stdout);

写点关键词防止迷惑行为大赏选不到我

原神 genshin 可莉 星穹铁道 芙宁娜 小粉兔

我要,去,WC，我想去WC，我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC我想去WC


X X XXX
O O OOO
XX X XXX
OO O OOO
X X X XXXX
O O O OOOO
XX XX XXXXX
OO OO OOOOO

HB赛区会有一位非常强的初二选手AK这场比赛，我不说是谁 

我不求别的，只要让我去得了冬令营就行

如果高一在去不了冬令营，我真成区了

别人估计都在注释里背追忆，但我不会背追忆，怎么办

冬令营是啥，不知道啊
APIO是啥，不知道啊
省队是啥，不知道啊


也许，这将是我最后一年打OI了
难度应该是橙绿青(紫/黑？)
非常CSP-S2024

 
*/ 
