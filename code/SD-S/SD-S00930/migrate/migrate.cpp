#include<bits/stdc++.h>
using namespace std;
using ll=long long;
namespace Solver_T3{
	int lp[2000005],rp[2000005];
	ll pos[2000005];
	ll dpl[2000005][3],dpr[2000005][3];
	int dis[5005];
	bool can[5005];
	void Elaina(){
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>pos[i];
		for(int i=1;i<=n+2;i++)for(int j=1;j<=2;j++)dpl[i][j]=dpr[i][j]=0;
		int p=1;
		for(int i=1;i<=n;i++){
			while(p<=n&&pos[p]-pos[i]<=d)p++;
			rp[i]=p-1;
		}
		p=n;
		for(int i=n;i>=1;i--){
			while(p>=1&&pos[i]-pos[p]<=d)p--;
			lp[i]=p+1;
		}
//		for(int i=1;i<=n;i++)cout<<lp[i]<<' '<<rp[i]<<'\n';
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n+4;j++)can[j]=0,dis[j]=-1;
//			dis[i]=0;
//			can[i]=1;
//			for(int j=i+1;j<=n;j++){
//				if(lp[j]==j)break;
//				dis[j]=dis[max(i,lp[j])]+1;
//				if(!can[max(i,lp[j])]||dis[max(i,lp[j])]==dis[max(i,lp[j])+1])can[j]=0;
//				else can[j]=1;
//			}
//			for(int j=i+1;j<=n;j++){
//				if(can[j]&&can[j+1]&&dis[j]==dis[j+1])dpl[j][2]++;
//				if(can[j]&&can[j+2]&&dis[j]==dis[j+2])dpl[j][3]++;
//				if(can[j]&&can[j+3]&&dis[j]==dis[j+3])dpl[j][4]++;
//			}
//		}
//		for(int i=n;i>=1;i--){
//			for(int j=1;j<=n;j++)can[j]=0,dis[j]=-1;
//			dis[i]=0;
//			can[i]=1;
//			for(int j=i-1;j>=1;j--){
//				if(rp[j]==j)break;
//				dis[j]=dis[min(i,rp[j])]+1;
//				if(!can[min(i,rp[j])]||dis[min(i,rp[j])]==dis[min(i,rp[j])-1])can[j]=0;
//				else can[j]=1;
//			}
//			for(int j=i-1;j>=1;j--){
//				if(j>1&&can[j]&&can[j-1]&&dis[j]==dis[j-1])dpr[j][2]++;
//				if(j>2&&can[j]&&can[j-2]&&dis[j]==dis[j-2])dpr[j][3]++;
//				if(j>3&&can[j]&&can[j-3]&&dis[j]==dis[j-3])dpr[j][4]++;
//			}
//		}
        for(int i=1;i<=n;i++){
        	if(rp[i]>i)dpl[rp[i]][1]++;
        	if(rp[i]-1>i)dpl[rp[i]-1][2]++;
			for(int j=1;j<=2;j++){
				if(rp[i]-j+1<=i)break;
				if(lp[rp[i]-j+1]<i)break;
				dpl[rp[i]-j+1][j]+=dpl[i][1];
			}
		}
        for(int i=n;i>=1;i--){
        	if(lp[i]<i)dpr[lp[i]][1]++;
        	if(lp[i]+1<i)dpr[lp[i]+1][2]++;
			for(int j=1;j<=2;j++){
				if(lp[i]+j-1>=i)break;
				if(rp[lp[i]+j-1]>i)break;
				dpr[lp[i]+j-1][j]+=dpr[i][1];
			} 
		}
		ll ans=0;
		for(int i=1;i<n;i++){
			ans+=dpl[i][2]*dpr[i+1][2];
		}
		cout<<ans<<'\n';
	}
	void Recall(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		ios::sync_with_stdio(0);cin.tie(0);
		int _id,T;
		cin>>_id>>T;
		while(T--){
			Elaina();
		}
	}
}
int main(){
	Solver_T3::Recall();
}
/*
Done T1 at 14:51.
Done T2 at 15:13.
t2大样例怎么这么水，算了一会再来看，先想t3 
首先t3答案显然就是平方级 
什么情况会有恰好两对最短路呢
首先位置是假的，实际上就是，每个点能够到达的最远的是哪个点
推一下最短路恰好2条的充要条件
那么就是，
首先两条最短路一定有交汇点是错的
比如
1 2 4 6 8 10
1 3 5 7 8 10
都是最短路，
诶不对
这样1 3 5 6 8 10 也是最短路了
所以，两条最短路，一定满足，至多一个点不同
然后，其倒数第二个节点，到上一个节点，一定满足有2或1条最短路
分治？？
n^2的dp是不是简单的
是简单的啊
先把 n^2 dp写出来，再想优化

然后，如果一个点不同，那这两个不同的点还必须是相邻的
感觉可以数据结构维护前缀和后缀的分别只有1条最短路到达这两个相邻的点的方案数
但是，这个怎么维护
如何维护？
如何 维护
如 何 维 护

先把n^2 dp写了 再去想如何维护
算了，先想如何维护，想不出来再去写dp
首先，我们可以定义c[i]为，i左边，到i和i+1都只有一条最短路的方案数
诶不对，这样把3个也算进去了
所以我们需要减去i-1 i i+1的答案，和i i+1 i+2的答案
但是这样，我去这样成为了一个容斥
哦不不不不不不我无疑是愤怒的
怎么能成为一个容斥呢
这不又n^2了
诶不对，我们是不是，只需要加上，i-1 i i+1 i+2的答案即可
算一下
(~i i+1~)-(~i-1 i i+1~)=(i i+1~)-(~i i+1 i+2~)=(i i+1)-(~i-1 i i+1 i+2~)
诶有道理啊
所以，我们怎么进行递推
i左边，到连续2~4个点都只有一条最短路的方案数
是不是直接推就行？
我试试吧

再推一下 转移：f[i][2]=f[lp[i+1]][2]?
首先，只有一条最短路，说明中间不能劈叉
比如，4-6-9和4-7-9都可以到达，是不行的
所以我们每次尽可能跳到远的地方？
首先可以求出最短路距离，就是我们每次贪心往前跳即可
我们先写个n^2的暴力，看看这个思路可不可行（就是2~4容斥）
我去看来这个容斥思路是不对的
是不对的！经过这个点，不一定是最短路
比方说最短路是1->10
我们会把 1->2->10和1->3->10这种给错误算进去
如何让他一定是最短路呢

我们先思考一下别的做法
我们考虑，其中一个最短路，一定是每次贪心跳最远
而最短路数量正好为2，说明每次可以恰好在其中一个地方反悔一次，少跳一格
还是只能枚举中间的反悔点啊，感觉
我想到一个dp，写一下试试 
那么，我们每次反悔，一定是在一个贪心点上
所以我们dp只需要维护到贪心点即可
不需要什么差分

看来思路还是有误
首先这个容斥就不该有，因为贪心点一重合就不需要容斥

神了，是r的转移忘了从从左往右改成从右往左了 
*/
