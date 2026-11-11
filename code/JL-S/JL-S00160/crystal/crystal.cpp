#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,minn=LONG_LONG_MAX,ans=1;
	cin>>n>>m;
	bool s=true;
	long long a[N],pre[N];
	pre[1]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long gc=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=gc)
			s=false;
	}
	if(s)
	{
		for(int i=2;i<=n;i++)
		{
			pre[i]=pre[i-1]+gc*(i-1);
			if(m-pre[i]>=0&&m-pre[i]<=minn)
			{
				minn=m-pre[i];
				ans=i;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		long long sum=0;
		for(int j=i-1;j>=1;j--)
		{
			sum+=a[i]-a[j];
			if(m-sum>=0&&m-sum<=minn)
			{
				minn=m-sum;
				ans=i-j+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
