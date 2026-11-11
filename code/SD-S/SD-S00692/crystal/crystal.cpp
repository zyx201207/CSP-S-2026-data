#include <bits/stdc++.h>
using namespace std;
const long long N=500005;
long long n,m,a[N],sum[N],maxn=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(long long l=1;l<=n;l++)
	{
		for(long long r=l;r<=n;r++)
		{
			if(sum[r]-sum[l-1]+m>=a[r]*(r-l+1))
				maxn=max(maxn,r-l+1);
		}
	}
	cout<<maxn;
	return 0;
}
//旗开得胜，马到成功！ 
/*
OK啊，我也是又来了，上午的J打完了，来打下午的S
上了洛谷迷惑行为大赏记得@我 (uid 1615028)
游记还是写一下吧，因为题都不会，实在没事干 
目录：
T1:前言
T2:自我介绍
T3:游记 
T4:继续放歌 
*/
