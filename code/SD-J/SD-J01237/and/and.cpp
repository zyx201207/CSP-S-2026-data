#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,a[200010],dp[200010];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=2147483647;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
//			cout<<dp[j]<<' ';
		}
	}
	cout<<dp[m];
	return 0;
}
/*
背包板子？ 

luogu:congcong2012
你也许会在S组的迷惑行为大赏中看见我（我猜的） 

9:53 为啥m=2的时候不对 

11:09 做完T4回来看T3 
密码的CCF今年怎么又考位运算
又是T3
C！ 

感觉T3拿不了多少了
希望今年分数线低一点 

11:14 怎么让背包必须选满m个啊
 
11:16 已经有开始玩冲浪的了
好想玩秘密实验室啊
好想玩旷野之息啊
为什么我周围都是原批啊
 
11:20感觉T3只能得零分了
赌一把背包板子
也许能拿20分？
但愿前两题满分
但愿今年分数线不要超过248
今年分数线要是比248还高CCF4000+

11:26 为什么背包在m=2时总是少算啊
别的样例都没问题

11:30 上完厕所回来
还是玩小恐龙吧
听天由命了

life1:919 
life2:498 
life3:612 
life4:426 
小恐龙好难
技术退步了
这个电脑太快了

还是去玩surf吧

11:38 祝愿I can't wait年底能上3000万播放量
祝愿T氏年底能上2000万播放量（虽然我忘了它现在多少了）
祝愿其他教主年底能上1000万播放量
快去给I can't wait刷到3000万播放量
祝愿I can't wait年底播放量能超过视奸 
祝愿I can't wait能拿下年榜榜一
电梯再快一点啊 

计时赛居然连1min都进不了了吗
水平还是退步了

第二次；54.98

11:56 第三次：47.67
这应该是最后一次了
这要是再不省一
我妈可能就要让我AFO了
再见！ 
*/
