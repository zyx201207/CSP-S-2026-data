//希望可以上luoguZJ整活打赏
//如果被选上整活大赏了私聊我一声可以吗，洛谷用户名cheeseA_A 
// 
//##########日记##########
//14:40看完四道题了
//感觉T1简单二分题（？），T2神秘建图技巧 
//T3神秘DP，T4神秘二分
//不管了先写T1
//15:06发现原先思路（枚举+双指针）假了，赶紧改成枚举+二分
//15:30思路完全乱了，先写下一题吧
//17:01回来继续看T1了！
//17:03又不想看了，去做T3吧
//17:09T3完全不会写，回来看一会T1
//17:11T1写起来好烦啊，去看看T4吧 
//17:21突然会写T1了，回来继续写T1（四渡赤水这一块） 
//17:48为什么小样例过了，大样例不输出？
//17:53原来是没开longlong见祖宗了。不对啊，怎么WA了 
//18:10大样例怎么还没过 
//18:10先保存吧 
#include<bits/stdc++.h>
#define N 500005
using namespace std;
long long n,m,a[N];
__int128 sum[N];
long long f(long long mid,long long i)
{
	long long l=lower_bound(a+1,a+n+1,a[i]-mid)-a,r=upper_bound(a+1,a+n+1,a[i]+mid)-a-1;
	return ((__int128)(i-l)*a[i]-(sum[i-1]-sum[l-1])+sum[r]-sum[i]-(__int128)(r-i)*a[i]);
}
int main()
{
	#ifndef DEBUG
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i = 1;i <= n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i = 1;i <= n;i++)//枚举基准 
	{
		long long l=0,r=1e12;
		while(l+1<r)
		{
			long long mid=(l+r)/2;
			if(f(mid,i)<=m)
			{
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		ans=max(ans,(int)(upper_bound(a+1,a+n+1,a[i]+l)-lower_bound(a+1,a+n+1,a[i]-l)));
	}
	cout << ans;
}
//ccf please give me 200 scores!
