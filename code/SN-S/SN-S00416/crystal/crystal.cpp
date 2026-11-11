//袁浩文 西安辅轮中学 SN-S00416
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define elif else if
#define pii pair<int,int>
#define lowbit(x) (x&-x)
#define fi first
#define se second
#define setdigit(x) cout<<fixed<<setprecision(x)
#define debug(...) fprintf(stderr,##__VA_ARGS__)
using namespace std;
const int maxn=5e5+5;
int a[maxn],c[maxn],m,tot,ans,n;
struct node{int l,r,x;}b[maxn];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	a[n+1]=inf,a[0]=-inf;
//	int m1=m,l=1,r=-1;
//	for(int i=2;i<=n;i++)if(m1>=a[i]-a[l])r=i,m1=m1-a[i]+a[l];
//	int ans=r,now=m1;
////	debug("the energy is %lld\n",now);
//	for(int i=2;i<=n;i++){
//		if(r==i-1)now=now+a[i]-a[r],r++;
////		debug("now is link %lld to %lld\n",l,r);
//		now=now+(a[i]-a[i-1])*(r-i+2)-(a[i]-a[i-1])*(i-l+1);//去掉右端到中心的贡献加上中心到左端的贡献
////		debug("if move the energy is %lld\n",now);
//		while(now<0&&l<i&&i<r){
//			if(a[r]-a[i]<a[i]-a[l])now=now+a[r]-a[i]-a[i]+a[l++];
//			else now=now-a[r--]+a[i]+a[i]-a[l];
//		}
////		debug("deal with error and now the l r energy is %lld %lld %lld\n",l,r,now);
//		while(now>=0&&r<n&&a[r+1]-a[i]<a[i]-a[l]&&l<i)now=now-a[++r]+a[i]+a[i]-a[l++];
//		while(now>=0&&now>=a[i]-a[l-1])now=now-a[i]+a[--l];
// 		while(now<0&&l<i&&i<r){
//			if(a[r]-a[i]<a[i]-a[l])now=now+a[r]-a[i]-a[i]+a[l++];
//			else now=now-a[r--]+a[i]+a[i]-a[l];
//		}
////		debug("try best to long and now the l r energy is %lld %lld %lld\n",l,r,now);
//		ans=max(ans,r-l+1);
//	}
//	cout<<ans;

//	for(int i=1;i<=n;i++){
//		int cnt=0,j=i;
//		while(cnt<=m&&j<=n)cnt=cnt+abs(a[i]-a[j++]);
//		j--;
//		ans=max(j-i+1,ans);
//	}
//	cout<<ans;

//	int cnt=0,r=1;
//	while(cnt<=m&&r<=n)cnt=cnt+abs(a[1]-a[++r]),debug("%lld\n",cnt);
//	cnt=cnt-abs(a[1]-a[r--]);
//	ans=max(r,ans);
//	debug("%lld %lld %lld\n",1,r,cnt);
//	for(int l=2;l<=n;l++){
//		debug("%lld %lld %lld\n",l,r,cnt);
//		if(r<l)r=l;
//		cnt=cnt-(a[l]-a[l-1])*(r-l+1);
//		while(cnt<=m&&r<=n)cnt=cnt+abs(a[l]-a[++r]);
//		cnt=cnt-abs(a[l]-a[r--]);
//		ans=max(r-l+1,ans);
//	}
//	cout<<ans;
}
signed main(){
	string filename="crystal";
	freopen((filename+".in").c_str(),"r",stdin),freopen((filename+".out").c_str(),"w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int Case=1;
//	cin>>Case;
	while(Case--)solve();
}
/*
9 4
0 1 2 2 3 8 8 8 100
*/
/*
写游记来
真服了上午J组T3神秘RE导致没有AK可能连一等都拿不到
希望下午能好一点吧
14:17
完了有点困
14:28
睡醒了，但还是有点困
14:30
OK彻底不困了
14:33
完了没读懂题
14:49
T1貌似不是那么简单
不是T2是我读错了吗
14:57
没读错但是有多次询问。。。
完了肚子疼
15:10
拉完回来了
15:16
半个小时了T1还不会
完了我要没救了
现在连着用啥算法都没想到
15:35
不会T1
真退役了得
15:44
好像有点会
不管了先把T2暴力打了
15:49
不对我不会
16:02
完了忘了dij咋打了
16:07
写回忆录吧写**游记
16:33
时间已经过半而我T1还没过
16:40
鸟儿咋飞关我什么事
16:53
样例过了但是大样例挂了
16:57
退役喽退役喽
17:10
完了我唐成啥了啊
最后1.5h看看能不能争
17:15
争个啥啊
17:40
诶
不写了不写了
爆零喽
17:47
彻彻底底的爆了零
所有洛谷关注了YHW12345都去取关
这个**不配让你们关注
//freopen//freopen//freopen//freopen//freopen//freopen
(bushi)
算了都要退役了那就乱写点吧
我的whk其实不能说不好
只能说一塌糊涂
初三了
whk很紧
拿出来这么多时间来搞OI还没搞出成绩
不知道怎么面对自己
或许看到我在这里写游记的都以为我AK了吧
（笑）
不想回去学whk
whk好难
写到现在游记已经写了1kb了
隔壁的已经AK开始玩游戏了
（笑）
我觉得教练真是看错了
当时说
一共15个人只有12个教练让留下来练
剩下3个本来是没想着的但是硬要来于是教练就把他们留了下来
现在看来
我觉得应该是只有一个
我
那3个我觉得都比我学的好
最近AT和CF涨分长得挺多的
但是没用啊你CSP不是照样爆零了吗
lz玩意
算了复习一会吧
庆历四年春，滕子京谪守巴陵郡，越明年，政通人和，百废俱兴，乃重修岳阳楼，增其旧制，刻唐贤今人诗赋于其上，属予作文以记之
啊啊啊这输入法好难用
予观夫巴陵盛状，在洞庭一湖，衔远山，吞长江，浩浩汤汤，横无际涯，朝晖夕阴，气象万千，此则岳阳楼之大观也，前人之述备矣
然后是啥
不会背了
（笑）
这是我的
whk水平
然后呢
我个fvv
用whk的时间来学OI
然后呢
爆零了
我是干啥的
哈哈哈
玩游戏？
爆零了你配玩游戏吗
之前有人说
他学这个不是为了升学
只是当做兴趣来学
那我问你
你浪费了你的时间，浪费了你父母的金钱，给CCF来送钱来，你值得你父母值得？
你学这
你学这就是为了玩个游戏吧
上课颓的跟狗一样
课后一个题不做
能考好才怪
去年好歹能看懂题大个暴力
今年呢
啥也不会
我觉得蛐蛐和wnn都能上200
sk也能有150
甚至小玩家也有100你信不信
就我一个颓佬
xt66666你没我颓
再写一点
先不压缩
我妈肯定又要说我了
现在我连我校直属高中都考不上了
包括它的分校
有人就要说了
啊你这学校不是名校吗考上有那么容易吗
额
你说得对
但是我是考不上吗
我是没有能力吗
我就是不肯学
那有有人要问了
那你倒是改变啊
（笑）
我改变什么
搞得跟我很有干劲似的
没有任何干劲
跟班里同学几乎没有共同话题
除了政治、黄色、猎奇没有任何话题
但我并不想聊这些
为什么不聊学习？
……
我想找个人聊游戏都没得聊
然后还给我安排个同桌
这不是让我影响他吗
我觉得
我就应该坐在最后一排那个小角落里
让我自生自灭吧
我是啥
前几天有个同学跟我说
诶你咋比我考的还低
我的回答是
你已经不是班级倒数了
我才是
确实
这次考试
我只有486.5/580
有的人可能觉得很强
但是在我们班我已经是倒数五名了
这次考试
我所有科目都没考好
语文95/120 数学112/120 英语110.5/120 物理66/80 政治68/80 历史45/60
说实话第一次看到这个成绩我甚至有点高兴
我拿去那么多时间来搞OI还能答成这个样子
但是其他人呢？
一堆元丘的不说了
剩下两个重点的都在前15
还有一个普通班的全班第一
我
虽然是个重点的
但是我是啥
我是全班倒数
我都不知道学校怎么给我分到这个班型的
加油吧
不知道我会不会上奇葩代码大赏
如果上了希望有人能给洛谷uid1494377私信
推荐一些西安好一点的职高技校
我这个成绩吧
我觉得重高线都过不了
都在码字
别人在码代码
我在这里写什么
我不知道
可以可以周一就去跟老师说让他给我调座位
好了快结束了
我的OI生涯快结束了
不知道等我上大学的时候还有没有ACM
想啥呢就算有也轮不到我
况且我能考上一所有ACM的大学吗
到时候肯定也会被初高中生踩爆
长度已经接近6kb了
不写了不写了要交了
希望能上奇葩代码大赏吧
*/
