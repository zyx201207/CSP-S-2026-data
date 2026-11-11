#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+15;
int n,m;
int a[N];
int tag[N],del[N];
int ans;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20)
	{
		for(int s=0;s<(1<<n);s++)
		{
			int num[21],cnt=0;
			for(int i=1;i<=n;i++)
			{
				int k=(1<<i-1);
				if(s&k)
				{
					cnt++;
					num[i]=1;
				}
				else num[i]=0;
			}
			if(cnt!=m) continue;
			int sum=(1<<31)-1;
			for(int i=1;i<=n;i++)
				if(num[i]) sum&=a[i];
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	for(int i=30;i>=0;i--)
	{
		int cnt=0;
		int k=(1<<i);
		for(int j=1;j<=n;j++)
		{
			if(del[j]) continue;
			tag[j]=0;
			if(a[j]&k)
			{
				tag[j]=1;
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans+=(1<<i);
			for(int j=1;j<=n;j++)
				if(!tag[j]) del[j]=1;
		}
	}
	cout<<ans;
	return 0;
}