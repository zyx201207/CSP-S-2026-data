//RP+=INF
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[500005];
int vis[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){//第i局
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){//从第j张牌开始
			if(vis[a[j]]!=0){
				for(int k=vis[a[j]];k<j;k++){
					vis[a[k]]=0;
				}
				vis[a[j]]=j;
			}
			else{
				vis[a[j]]=j;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]!=0){
				ans[i]++;
//				cout<<i<<' ';
			}
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
//土力架真好吃
/*
碎碎念：
额啊终于写完了
T1模拟
T2双指针（疑似？）
T3骗分
T4骗分
预期得分273
二等...也行吧知足了（万一呢运气好一点真给我冲上一等了）
几年OI就当大梦一场罢了
还有半个多小时干嘛呢...
喔差点忘了自我介绍了
luoguID：737134
坐标0574，NBDXFSXX，nan
一个初中四年才进一次J复赛，连绿题都切不了的蒟蒻
哇哇哇这次T3T4能骗70是实在想象不到的
不行了好无聊
好想玩phigrosmaimaiarcaeaendfiled异环CS2warthunder阿巴阿巴
诶你（不管你是谁）说我这次不会突然爆零然后拿三等吧
*尝试读懂自己写的代码中*
算了已经看不懂自己的代码了
我朝为我旁边两个选手看起来好认真啊，到现在键盘没停过
他们不会都是OI大手子吧
可惜了考场里没有人cos OI(fighter)模拟器的主角
太好了只有15min牢坐了
*/