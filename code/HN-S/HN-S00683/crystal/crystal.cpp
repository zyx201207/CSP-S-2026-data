#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define I using
#define AK namespace
#define IOI std;
I AK IOI
struct jt
{
	unsigned long long start,sum,s;
}ans[500005];
int n,m,a[500005];
unsigned long long answer=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ans[1].start=1;
	ans[1].s=1;
	for(int i=2;i<=n;i++)
	{
		ans[i].s=ans[i-1].s+1;
		ans[i].start=ans[i-1].start;
		ans[i].sum=ans[i-1].sum+(i-ans[i].start)*(a[i]-a[i-1]);
		while(ans[i].sum>m)
		{
			ans[i].sum-=(a[i]-a[ans[i].start]);
			ans[i].start++;
			ans[i].s--;
		}
		if(ans[i].s<ans[i-1].s)cout<<ans[i].sum<<" "<<ans[i].start<<" "<<ans[i].s<<endl;
		answer=max(answer,ans[i].s);
	}
	cout<<answer;
	return 0;
}
