/*
14:07 hi.@[tzhengqing](/user/1058570) here.

well well, so many things happened these days.
(such as got banned in florr.io?)

CSP 2023 5+85
CSP 2024 320+180
NOIP 2024 204
CSP 2025 214
NOIP 2025 124

what will go on next?

to be honest there's no reason to learn OI anymore, but I still go on.

that's the charm.

all in all,welcome to join qaswed12 OI Round 2.(oh no i forgot the link, maybe 361669? seems to be not lol)

coffee tastes good.

(try to find the wrong usage of the grammar! quite funny)

I guess emojis are ok. but there is 1% chance I got 0pts, that's bad.

maybe I shouldn't be here, cuz I forgot most of the lyrics. oh no.

---

I used 11min to print the text upside. Coding time now.

CSP-S 2026 AK +++!

---

15:43 T3 code here.

怎么是 ds，就没有我擅长的东西吗。

哎哎 2e6 感觉不像啊，兴许能做？

没事没事这场后面暴力也行了，过了 2 题感觉已经相对成功了。

还是分析一下这题，感觉其实并不难。

你钦定 dp[i] 表示从 1 飞到恰好 i 的最短距离，那么转移显然是一段后缀min+1，容易发现后缀 min 也是一段区间。

但是差分不太好研究，我们换一个角度，发现合法的答案一定是一段前缀，一段后缀加上中间一个两步的过程。

中间的两步好找，只需要往后跳两个最远的，并判断上一个和上两个能不能跳即可。

前后缀彼此等价，只考虑后缀。

那后面的数至少只能跳到这里而非前面，所以范围在 [d-dis,d] 之间。

再往后一个就是也要判断跟当前的 r 能不能形成 >=2 路，如果合法的话则拼上后面的方案。

换成前缀吧，考虑 dp[i] 表示 i 往前有多少个点方案唯一，  
转移就考虑如果 [i-2d,i] 有 >=2 的方案就统计答案 +=dp[i-2d+eps]，并置 dp[i]=dp[i-d+eps]+1，  
否则置 dp[i]=dp[i-d+eps]+1.

哎哎怎么是一样的。感觉有问题。

这样下去不太行啊。

16:52 上了个 WC 感觉直接通透了，dp[i] 就是 cnt[i-d,i]+dp[i-2d+eps]-1 呀。  
哦这又不太对。

算了算了直接启动 Plan B，钦定这题不可做，开始写暴力。

根据刚刚的分析直接写暴力，从每一个点开始前缀 dp。

什么叫做 3-pointer。

今天我写的代码怎么基本都是一遍过，不用调的，rp这么好。

来来来特殊性质耍起。

100=100+40+0=240 right now，感觉好菜但是算了。

好糖啊，T4 根本不会。

人均分都不止这么点。/ll/ll

喵喵喵，去年 7 钩今年 6 钩的来。

开始骗分吧！注意到，除了序列被超级分段导致的截断之外，如果 dp 值达到 4，大概率就不会重新变成 2 了，于是可以直接截断！  
考虑如何实现这个事情！

17:41 后面的神秘数据都过了，考虑如何把前面的判掉！

完了完了，发现后面的全是小数据，原来都是暴力过的。zzz

哦耶，完蛋了。

考虑转移只枚举 dp2[i] 的最后两个数，这样对正确性似乎没有影响。

还要写线段树，不知道写不写的完。qwqwqwqwq

哎哎好像并不需要啊。

好像有大问题，还是不写了。

6 钩大王来袭！！！

upd:蠕动了 8 分。
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005,p=998244353,inf=100000000010299ll;
int c,n,d,a[N],dp[N],sum[N],dp2[N];//dp2[i] 表示数值，dp[i] 表示方案数。
void sol2()
	{
	cout<<(d<2*(a[2]-a[1])?0:max(0ll,n-d/(a[2]-a[1])*2+1))<<'\n';
	}
void sol()
	{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>5000){sol2();return;}
	int ans=0;
	for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=n;j++)dp[j]=sum[j]=dp2[i]=0;
		dp[i]=sum[i]=1;dp2[i]=0;int l=i,now=i;
		for(int j=i+1;j<=n;j++)
			{
			while(a[l]+d<a[j])l++;
			dp2[j]=dp2[l]+1;
			while(dp2[now+1]==dp2[l]&&now<j-1)now++;
			dp[j]=max(0ll,sum[now]-sum[l-1]);
			sum[j]=sum[j-1]+dp[j];
			}
		for(int j=i+1;j<=n;j++)ans+=(dp[j]==2);
		}
	cout<<ans<<'\n';
	return;
	}
signed main()
	{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>c>>t;while(t--)sol();
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//Need space here.
