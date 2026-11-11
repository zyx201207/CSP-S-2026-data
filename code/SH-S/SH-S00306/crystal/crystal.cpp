#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std; 

const ll N=5e5+5;

ll n,m,res,a[N],s[N],b[N];
bool flagA=1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	for (ll i=1;i<=n;i++)
	{
		cin >> a[i];
		if (i>=2 && a[i]!=a[i-1]) flagA=0;
	}
	
	sort(a+1,a+n+1);
	
	if (a[1]<=0)
	{
		ll delta=abs(a[1])+1;
		
		for (ll i=1;i<=n;i++)
		{
			a[i]+=delta;
			s[i]=s[i-1]+a[i];
		}
	}
	
//	for (ll i=1;i<=n;i++)
//	{
//		cout << a[i] << " ";
//	}cout << "\n";
//	
//	for (ll i=1;i<=n;i++)
//	{
//		cout << a[i] << " " << s[i] << "\n";
//	}cout << "\n";
	
	if (flagA)
	{
		cout << n;
		return 0;
	}
	
	for (ll i=1;i<=n;i++)
	{
		b[i]=a[i]*(i-1)-s[i-1] ; // 你需要多少
	}
	
	res=upper_bound(b+1,b+n+1,m)-b-1;
	cout << res;
	return 0;
}

// freopen
// luogu
/*
这里是曹阳二中考场，图书馆
巨大的图书馆，舒服的椅子，巨大的桌子
高高的天花板，小二层和小地下层
一定要考1=

密码：Oct31==Dec25? 

14:35 感觉90pts思路，开t1 
14:49 写出O(n)做法 
14:54 过crystal样例1
14:55 过样例2
14:56 炸样例3 
15:07 调啊调 
15:26 还没有调出3 
15:40 创造偏移量，全部搞成正整数，3就完事了 
15:41 炸样例4 
16:05 还没有调出来
16:10 决定用dij试一试t3
16:24 完成t3 bfs40分部分分代码
16:31 绝望了，migrate调不出来 
16:43 太绝望了，感觉要AFO了 
17:03 啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
17:11 成功写出T3 O(tn2)，预估40 
17:16 吃三明治 
17:41 写完hub的状压dp解法，炸了，133行
18:00 （CSP-S 2026 rift结算时刻）The match is over. Good-bye.
China_TSJ77 is the loser of the match.
18:01 不对，还有半小时！ 
18:20 写完T3中的散文，再见 

70+0+40+15=125

我常常追忆过去。
生命瞬间定格在脑海。我将身后的时间裁剪，折叠，蜷曲，揉捻成天上朵朵白云。 
云朵之间亦有区别。积云厚重而卷云飘渺。生命中震撼的瞬间掠过思绪便一生也无法忘怀，而更为普通寻常的记忆在时间的冲刷下只留下一些残骸。
追忆宛如如梦。太过清楚而无法愉悦自己的幻想，太过模糊又坠入虚无。只有那薄雾见的山水，面纱下的女子，才能满足我对美的苛求。
追忆总是在不经意间将我裹进泛黄的纸页里。推导又重建的街道，分别又重聚的朋友，种种线索帮我从时间的河逆流而上。
我只不过是一个过客，但是，我仍然希望在每一次追忆旅途中留下啊美好的记忆，这便让我心满意足。
只是记忆时常疏于保管，回忆也在改变着各自的形态，这给我的追忆旅途带来许些挑战。
我该在哪里停留？我问我自己。 、
——省选联考2025 追忆 

luogu: @chillchill 
*/
