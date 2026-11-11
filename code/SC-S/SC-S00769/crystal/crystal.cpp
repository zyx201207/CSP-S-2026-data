#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,a[500005],s[500005],sum[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		s[i]=a[i+1]-a[i];
	}for(int i=n-1;i>=1;i--){
		s[i]+=s[i+1];
	}for(int i=n-1;i>=1;i--){
		sum[i]=sum[i+1]+s[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(sum[mid]-sum[i]-(i-mid)*s[i]<=m)r=mid-1;
			else l=mid+1;
		}ans=max(ans,i-(r+1)+1);
	}cout<<ans;
	return 0;
}
/*
14:32 解压
14:32 读 T1
14:34 一眼二分答案，直接写。
14:38 等一等，好像有点不会
14:41 CSP竟然会延时？那么好
14:43 有思路，不急，看下一题
14:45 T2 可以暴力建图跑最短路，不急，看 T3
14:48 T3,T4 除了暴搜暂时想不到解法
14:49 细想 T1......
15:06 切掉 T1！
15:06 想 T2
15:14 N 很小，能否Floyd
15:29 T2 写完了一篇代码，测下大样例
15:32 大样例全过了，最慢 0.6s，感觉有点悬，到时候再卡卡常吧
15:35 T3 40pts 好像很好写（O(n^2) 建图后暴力），
不急但是好像以我的实力已经无法切出 T3 了，
不管，先试试再说，时间还多。
15:56 开始了 1.5h 这时候 J 组应该都 AK 了，
对了我是 SC-J00465（可能写错了，反正差不多）
S 组才两道题，其实也可以了，打暴力吧。T3 写O(n^2)
16:33 离考试结束还有两个小时（怎么还有两个小时），
T3 暴力假了，变成 O(n^3) 了，40pts->24pts。
其实感觉已经稳了，但是心里还是有点慌。
16:35 T4 暴力都写不来怎么办！还是多测！！！
16:36 好像可以暴搜，但是 5pts 我不是很瞧得起。
17:04 算了，还是瞧得起，5pts 入账
17:05 差不多了，上虚拟机跑一下
17:07 虚拟机上跑过了
17:08 上午没有看到蜘蛛纸牌，下午逛到了，玩会？打不开，坏了
17:09 提交一下
17:10 离考试结束还有一个半小时，写写总结

# 总结
下午是 CSP 的 S 组，不出意外的话应该是写出来了 T1 T2，
T1 : 后缀和再二分查找就行了
T2 : 对于每一个站点建出以地铁为点的图，然后 Floyd 就行了。
T3 : 感觉跟计数有关系，但不会
T4 : 感觉是二分答案+check，但不会
大致定义难度：黄(中绿~下青)(不会)(不会)
不会根据以前 S 组惯例应该大致是（蓝/紫）（紫/黑）

17:16 写完了总结，还是要求一下我要上迷惑行为大赏。
17:17 估下分，J 组大概 100+100+100+100=400pts
S 组预估 100+100+24+5=229pts
但是可能会挂成：100+[80,100]+24+[0,5]=[204,229]
管他的，1= 了就行。
17:22 无聊
17:24 算了，想想 T3 正解。
17:39 使用换脑子机会，发现还是不会......
17:45 玩一下电脑设置
18:05 最后半个小时了，检查调试有没有删完
18:10 坏事了，别人看起来好努力，我好像一直没有干正事
18:12 写个 rp++ 祝福我。今年怎么没有不可以总司令（tao
18:15 突然感觉心里好慌......我不会直接 AFO 了吧(贡献AFO两次)
18:23 玩会计算器
18:24 检查一下多测清空
18:25 再跑一遍虚拟机
18:28 OK，检查完毕，静等结束
18:35 离场

qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq
qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq
qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq
qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq
*/