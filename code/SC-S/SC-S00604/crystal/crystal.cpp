#include <iostream>
#include <algorithm> 
#include <cmath>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
const ll INF = 1e13;
ll n,m,tot = 0;
ll a[N];
ll ans = INF * -1;
//先将输入的水晶大小按升序排序
//若是DP，则绝对不能按背包来做，m或炸掉时间
//建立一个类似于滑动窗口的东西，因为已经排序，所以选择的一定在连续的情况下最优
//建立二位DP[l][r]，考虑如何迭代？当向右边拓展时，sum会加上（原本数量*新旧末尾的差值的偏移)
//向左边偏移时，会减去末尾减去这个值的偏移
//等不能贪心？等等，这样的话会比单纯的O^2更快，直接实现
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	//dp武器
	ll l=1,r=1,cost=0;
	while(r<=n)
	{//区间长度r-l+1 
		while(cost+(r-l+1)*(a[r+1]-a[r]) <= m && r<=n)
		{
			cost += (r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		ans = max(ans,r-l+1);
		while(cost+(r-l+1)*(a[r+1]-a[r]) > m)
		{
			cost -= (a[r] - a[l]);//把al补全成ar的花费
			l++; 
		}
	}
	cout << ans;
}