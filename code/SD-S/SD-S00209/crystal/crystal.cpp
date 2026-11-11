#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

const int N = 5e5 + 10;
ll arr[N], sum[N], f[N];

int main() {
	std::cin.tie(0) -> sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	std::cin >> n >> m;
	ll mina = 0x7fffffffffffffff; 
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i]; 
		mina = std::min(mina, arr[i]);
	}
	 
	for (int i = 1; i <= n; i++) {
		arr[i] -= mina;
	}
	std::sort(arr + 1, arr + n + 1);
	
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}
	
	f[1] = 1;
	ll ans = 0x8000000000000000; 
	for (int i = 2; i <= n; i++) {
		ll l = f[i - 1];
		while ((i - l + 1) * arr[i] - (sum[i] - sum[l - 1]) > m) l++;
		f[i] = l;
		ans = std::max(ans, i - f[i] + 1);
	}
	std::cout << ans << endl;
	return 0;
}

/* 

luogu @longlong_int(1059747) 

	// freopen("crystal.in", "r", stdout);
	// freopen("crystal.out", "w", stdin);

做迷惑行为大赏并挨个翻代码的同志们你们辛苦了（by longlong_int, 14:47 
哦对了给我这么长的注释用折叠框折起来吧 


14:59 不行写个前情提要吧。

Day -1，下午 16:00
@ProtectEMmm：你知不知道有个东西叫 INT_MAX，有个东西叫 LLONG_MAX。
我：我知道但是我不太想写。（屏幕上出现 0x7fffffffffffffff） 

Day 0，早上 08:30
yjz：“你一定会取得绝佳的佳绩。”
@TChQ(1004463)（SD-S00021 还是 22 或者 23 或者 24）：“我要是 T1 没过就要被 @l*****n 老
师压力了”

Day 1，早上 10:00
@VictorW：你们肯定都有拿 1= 的实力。 

14:28 拿到 PDF，开 T1。Oct31==Dec25?
14:28 这个 T1 怎么这么简单（
14:28 貌似有思路了
14:30 开。话说我电脑时间流逝怎么这么快
14:37 写一下这个游记从这开始往前的部分 
14:38 注意到不开 long long 见祖宗 

14:42 注意到下文

中国计算机学会是很善良的孩子们，我们如果想要把所有的 a_{i} 都减去 min A
以变成正的，那么全局就会加上 5e17，刚好不炸。 

14:45 依旧 SWUT 神秘铃声，但是好好听啊，空灵美丽。

14:55 还有铃声（应该是上课铃）

14:56 得以进行下去 T1。

需要找出最后一个满足 (i - l + 1) * arr[i] - (sum[i] - sum[l - 1]) <= m 的 l。
考虑 two-pointer 思想：排序后 l_i 一定大于 l_{i-1}。于是设 f[i - 1] 为在 i - 1 处的 l
可以 while ((i - l + 1) * arr[i] - (sum[i] - sum[l - 1]) > m) l++。

15:06 突然想起来个事，昨天晚上试机的时候我发现在我这考 J 的 SD-J01995 开了 -Werror 以防止
他不看警告。 

15:07 写完。-Wconversion 救了我一命。
[Warning] conversion to 'int' from 'll {aka long long int}' may alter its value [-Wconversion]

15:08 开始测试。

Sample 1 AC
Sample 2 AC
Sample 3 AC
Sample 4 AC

fc crystal.out crystal1.ans
正在比较文件 crystal.out 和 CRYSTAL1.ANS
FC: 找不到差异

fc crystal.out crystal2.ans
正在比较文件 crystal.out 和 CRYSTAL2.ANS
FC: 找不到差异

fc crystal.out crystal3.ans
正在比较文件 crystal.out 和 CRYSTAL3.ANS
FC: 找不到差异

fc crystal.out crystal4.ans
正在比较文件 crystal.out 和 CRYSTAL4.ANS
FC: 找不到差异

15:12 一次 AC，T1 用时 42min，难度评价：中上位橙。

我们还有很多时间，不妨先去写剩下所有题的暴力然后再回来打对拍。

15:13 666 直接忽视省级特派员在 CSP 考场门口炸街的来了（大学生在大学城炸街（（ 

PDF 的 SHA256 为 14F8F1933B179F383DDCA940CB228DD8A2C939C999DFB95977BE4B6A48B88339，请核对。 
 
*/
