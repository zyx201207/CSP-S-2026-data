#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int num[500005];
int ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>num[i];
	sort(num+1,num+1+n);
	int l=1,r=1;
	int en=0;
	for(int i=2;i<=n;i++)
	{
		r++;
		int len=r-l+1;
		int ned=(num[i]-num[i-1])*(len-1);
		en+=ned;
		if(en<=m)
		{
			ans=max(ans,len);
			continue;
		}
		while(en>m)
		{
			en-=(num[i]-num[l]);
			l++;
		}
		len=r-l+1;
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
