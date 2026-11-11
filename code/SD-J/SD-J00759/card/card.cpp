#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500100],sum[500100],ans[500100];
stack<int>st; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)sum[j]=0;
		while(st.size())st.pop();
		for(int j=i;j<=n;j++){
			if(sum[a[j]]){
				while(a[st.top()]!=a[j]){
					sum[a[st.top()]]--;
					st.pop();
				}
				sum[a[st.top()]]--;
				st.pop();
			}
			st.push(j);
			sum[a[j]]++;
		}
		while(st.size()){
			ans[a[st.top()]]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

/*
前面的部分看T3 
9:17 开T4
9:21 发现了一个思路 
9:23 上厕所
9:32 发现9:21的思路进行不下去，所以把9:21的思路删了，并发现新思路：其实把a反向除了第i轮是从1到i外题目相同
9:33 9:32的思路更可做一些，然后考虑怎么删
9:34 其实我们可以维护一个牌栈，然后我们发现能收就收，对于每一个牌计算它的存活时间，然后就这么做
9:35 这有点像小猫钓鱼，先写代码  
9:42 upd:完了忘记插入牌了，增加第25行 
9:48 RE on pretest 2，进行4处修改
10:07 发现思路假了
10:20 发现我们可以重返9:21想的思路，i->i-1，若i颜色为j，则i->i前面中离最近的颜色为j的
然后跑n->n-1,n->n-2...n->1,n->0的最短路，删掉最后一个点，点在最短路中的出现次数就是结束时留牌的次数
然后建最短路树就行了，每个点的出现次数为它的子树大小-1 
10:24 衣服线断了，花了1分钟修好，开写代码 
10:46 发现核心问题：其实我们这题需要对每一个颜色都搞一个超级源点，然后i->i颜色，i颜色->i-1，重新修改
10:53 那这样直接DP不就行了
11:15 思路假了
11:22 彻底怒了，我不会 
11:52 写了个暴力，走人 
*/ 
