#include<bits/stdc++.h>
using namespace std;
const int N=505050;//所有人保持苹果肌松驰。
long long n,m,a[N],qzh[N],ans=1,mid,l,r;
//熊大熊二，你们俩好好干活，我待会后面写T4的树别被光头强砍了！
//我在这里偷偷和 @JXR_Kalcium 表个白，但是她肯定不知道，因为是机器评卷。 
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)qzh[i]=qzh[i-1]+a[i];
	for(int i=2;i<=n;i++){
		//目标：合成i号musical crystal
		l=1,r=i-1;
		while(l<r){
			mid=l+r>>1;
			//check if [mid,i-1] can be combined within the cost of m
			//req=[len]*a[i]-sum[mid,i-1]
			if((i-mid)*a[i]-qzh[i-1]+qzh[mid-1]<=m)r=mid;/*able to use*/
			else l=mid+1;//合成失败，musical crystal炸掉了qwq。
		}
		if((i-l)*a[i]-qzh[i-1]+qzh[l-1]<=m)ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
T1主要元素是Xterfusion同款大！？musical crystal？！
今天是Xterfusion发行一周年的日子，我肯定不能错过整活！

- - --- - - ---Xterfusion - REDALiCE & t+pazolite - - --- - - ---
（前奏）
（BASS UP）X! X! XXX!
X! X! XXX!
X! X! XXX!
XXXXXXXX 3,2,1,GO! (！？DESTRUCTION 3,2,1暗示？！)
X X X X X X X X XXX X X X xXXX XXX X X X XXX xXx XXX
X~~ xxX X X!
X X X X X X X X XXX X X X xXXX XXXxx Xxx X YEAH Xxx Xxx COME ON
(旋律)
【下面插播一则广告】 
Only feels like nothing could be better when I'm with you when I'm with you~ ~ ~~~
Dancing all night pray we meet together it's a breakthrough it's a breakthrough~ ~ ~~~
musical crystal合成中...
X X XXX
x x xxx
XX X XXX
xx x xxx
X X X XXXX
x x x xxxx
XX XX XXX X X
xx xx xxx x x
X X X
x x x
XXX X
xxx x
XXX XXX
xxx xxx
XXXXX
xxxxx
XXXXXXX
xxxxxxx
XXX X X
xxx x x
XX xx XX xx XX xx XX xx
XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXx
↑↑↑↑↑↑↑↑~~~~~~~↘
（一阵激烈的立绘展示）
Only feels like nothing could be better when I'm with you when I'm with you~ ~ ~~~【故障音效】 
（一阵劲爆的旋律）
X!（上升的雷霆刺耳音效）X!
*/
/*
14:59 **大样例还得自己搓。。。
15:03 我第一次觉得 "w" 这三个字符有点可爱...
15:05 机房有人使用了O2优化，大家普遍喘不过气，
但是我有拼多多抢来的氧气瓶，[详情请看蓝链](https://www.bilibili.com/video/BV1fEy8BoEbj)。
//froepen("crystaI.incyde","W",stdint);
//freeopen("crysta1.out","r",str_1)；
15：13 整完了T1所有可以整的活，并且故意（？）留下了一个错别字。 
*/
