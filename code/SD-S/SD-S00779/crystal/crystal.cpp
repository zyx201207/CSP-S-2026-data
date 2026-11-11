#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[514514], sum[514514], n, m;

int solve (int x)
{
	int l = x, r = n, mid, ret = 1;
	
	while (l <= r) 
	{
		mid = l + r >> 1;
		
		if (a[mid] * (mid - x + 1) - (sum[mid] - sum[x - 1]) <= m) 
		{
			ret = max (ret, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}
	
	return ret - x + 1;
}

signed main()
{
	
	//score += 100
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
    	cin >> a[i];
	}
	
	int ans = 1;
	
	sort (a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
	
	for (int i = 1; i <= n; i ++)
	{
	    int t = solve (i); //i为区间左端点的最大水晶个数和 
		
	    ans = max (ans, t);
	}
	
	cout << ans << endl;
	return 0;
}
/*

luogu uid 787512 求壶关喵。（有意者记得发私信） 

CSP-S2026游记

## Day 0:坐车来到日照。遇见一个阳光开朗大男孩（以下简称bro）。聊天。 

打了一路的游戏，艹绝航怎么这么难打。（想一起打州的可以私我）

中午和bro吃饭，bro没手机，就让他玩我的（我还有一个平板）艹给我手机弄得全是油

回到酒店，我们是校园内部那个酒店，没有房间了，所以my mother（下面简称我M）订了一个叫什么总统套房。

我去这个房间可以啊，居然有4个房间，客厅+2厕+卧室，豪到我了，这么极品

晚上和bro一起式鸡，本来以为都是一个考场，完事我等了半个小时要和他一起进去，结果一看发现一个A考场一个B考场，天塌了，艹白等了 

不过玩了30分钟JJ象棋，也还不错

## Day 1 

上午 

一直在听 命に嫌われている。（好听miku唱的已经听了520遍） +打洲 

下午

和bro一起进去，此处省略1e18个rp++，crush居然也祝我顺利，牛大了

### 0s 

注：以下时间均为开考的时间 

解压。读题。第一题水的过分了吧？？排序+二分秒了（此时不会测大样例，只能手动复制C++上面然后每个行末加空格） 

## 30min

速切T1 

第二题本来写一些特殊性质72分的，但是写到B的时候突然发现把地铁看成点1~n，对于能够换乘i号与j号地铁的点k，其t_{i,k} + t_{j,k}（注意此处t_{i,j}与原题有出入，此处表示第 j 个地铁站的大堂到第 i 号地铁线路的距离）可以看成 i,j两点间的边权

注意会有重边，所以取min。因为n只有500，所以最后一个floyd秒了。统计答案的时候枚举x，y分别有哪些线路经过，挨个枚举就行，时间复杂度 o(n^3+md^2)，比较极限能够通过本题 

##2h

此时T2已过，开始写T3的特殊性质A以及暴力。

本来想推个正解发现压根不会。（本人实力S第一题都过不了） 

获得32分。 

## 3h

测试T1与T2大样例，会测试了。T1大样例过

T2因为本地太烂只能测到#4，过了，因为理论时间复杂度完全够用，但是本地编译器太烂，导致m只有1000的#4也运行了1秒多。 

其余的回家再写。 
*/

