#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],ans,cnt,sum;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;	
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(sum>m)
		{
			sum-=a[i]-a[i-cnt+1];
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
} 
/*
我要上迷惑行为大赏 HN-J01554也是我

T1这么简单吗？ 不是一个双指针就可以了吗？

0h16min AC
*/ 
