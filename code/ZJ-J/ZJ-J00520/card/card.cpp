#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=5e5+5;
int n,m;
int a[N];
int id[N],to[N];
int ans[N];
void work(){
	for(int i=1;i<=n;i++){
		ans[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		ans[i]+=ans[i-1];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<" ";
	}
	cout<<"\n";
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=1;
	for(int i=1;i<n;i++){
		if(!(a[i]<=a[i+1])){
			flag=0;
			break;
		}
	}
	if(flag){
		work();
		return ;
	}
	for(int i=n;i>=1;i--){
		if(!id[a[i]]){
			id[a[i]]=i;
		}
		to[i]=id[a[i]];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			j=to[j];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<" ";
	}
	cout<<"\n";
} 

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
/*
[80-100]pts

ZJ 2026 CSP-J游记

UID:917375
准考证号：ZJ-J00520
CSP再爱我一次，已经给西西弗交了3次钱了 

估分：100+100+100+[80-100]=[380-400]pts

n^2过10万

最后一题看数据了，大概率只有80左右

Day -998244353

开始集训，暑假集训2个月，开学后立刻开始半脱产，现在已近初二了，必须努力了
去年J组T2看错n，m痛失1等，S组因为太菜了只做出T1，T2T3部分分都没打，我是区

Day -7 ~ Day -2
 
集训以后基本每天一次模考，我也依旧稳定发挥，每次都挂分，导致每次S都从一等线挂到二等三等线，有点小慌
唯一考好的一次是10月29号的模考，绿蓝蓝黑破天荒没有挂分195pts，紧接着信心赛 黄绿绿清 爆炸只有180pts，直接急哭

Day -1 

乘坐NBFLS的大巴出发去杭师大，路上休息了一下，打了会thoita，结果出了第一个super：salt（玩过的都知道含金量）
晚上吃了个超辣的饭（我不吃辣），就回酒店了，略微复习了几道简单题就休息了

Day 1

期待已久的这一天终于到了，6:30就被家长的洗漱声叫醒了，一开始有点紧张，但后来就放平了心态，毕竟都打了这么多场模拟赛了，
经验还是有一点的，8:00进到机房，没去面积，但开到了一些初中同学和小学同学，挺开心，依旧15号机位，在门的正前方，
开考前不让碰键盘，只好在座位上看门口有没有认识的

解压密码：Trick||Treat!

开考直接顺序做题，感觉T3<T1<T2

T1T2可能是太久没做简单题，竟然想了10分钟，有点慌，J不会要崩吧

35分钟速通了前两题，一点都没调

看T3一眼以为是类似去年的T3,3分钟后想到一个奇怪的二分，
写完没调就过了大小样例，有点小惊讶，算了一下复杂度大概是1.2e8跑不满，遂扔掉

看T4觉得是简单题，但懒得写了，随便写了个神秘n^2大样例飞快，又打了个特殊性质A，
过了我造的大部分数据，估计至少能拿80，希望西西弗评测机发力能再给我送点分

一个半小时就打完了所有，遂摆烂，开始写现在这篇游记（当前时间：2026年10月31日10:47:59）

继续检查 

T3炸了 

只剩[55-100]pts 
*/
