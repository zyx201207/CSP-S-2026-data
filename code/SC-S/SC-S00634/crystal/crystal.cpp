/*
我们考虑一颗水晶一颗水晶的增加，一颗水晶加上一个值可以达到下一个水晶，如果能量不够了，使用滑动窗口来减少最小值，时间复杂度 O(n)，还有排序的log 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1008617];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,less<int>());
	int l=1,r=0,ans=0,sum=0;
	for(;r<=n;r++)
	{
		if(r!=1)sum+=(a[r]-a[r-1])*(r-l);
		//cout<<sum<<' '<<l<<' '<<r<<'\n';
		while(sum>m)sum-=(a[r]-a[l]),l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
/*
accepted 14:49 100pts total:100pts 
*/