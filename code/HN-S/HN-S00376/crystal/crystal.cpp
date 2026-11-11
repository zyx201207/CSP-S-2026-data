#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,ans=1,now=0;
	while(l<n)
	{
		while(r<n&&now+((a[r+1]-a[r])*(r-l+1))<=m)
		{
			now+=((a[r+1]-a[r])*(r-l+1));
			r++;
		}
		ans=max(ans,r-l+1);
		now-=(a[r]-a[l]);
		l++;
	 } 
	 cout<<ans;
	return 0;
}
//HN-J00507也是我，上午T2双指针(虽然我写的二分+分块），下午又考是什么意思，我双指针是最差的，还忘记复习了 
//15:22四则运算都不会了，20行 now+((a[r+1]-a[r])*(r-l+1))居然能写成now+((a[r+1]-a[r])*r-l+1) 
//15:23 T1确认AC，T2争取2h以内AC
//15:24 先把T3暴力写了，T2太难阅读了 
