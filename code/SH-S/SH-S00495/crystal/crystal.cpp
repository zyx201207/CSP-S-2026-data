#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll m,a[500005],b[500005],sum[500005];

bool check(int x)
{
//	int minid = 0;
	ll minn=0x7f7f7f7f7f7f7f7f,ans=0;
	for(int i = 1;i<=n-x+1;i++)
	{
//		int cha = sum[i+x-2]-sum[i-1];
//		if(cha<minn)
//		{
//			minn=cha;
//			minid = i;
//		}
		ll tmp=0;
		int t = i+x-2;
		tmp=(x-1)*sum[t]-b[t-1]+b[i-2];
//		printf("x:%d,i:%d,tmp:%d\n",x,i,tmp);
//		for(int j = 1;j<=t;j++)
//		{
//			if(tmp>=minn)break;
//			if(f[j][t])
//			{
//				cout << "!"; 
//				break;
//			}
//		}
		if(tmp<minn)
		{
			minn=tmp;
		}
	}
//	cout <<x<<'!'<< minn<<"\n";
	return minn<=m;
//	int t = minid+x-1;
//	for(int i = minid;i<=t;i++)
//	{
//		ans+=a[t]-a[i]; 
//	}
//	return ans<=m;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<n;i++)
	{
		int cha=a[i+1]-a[i];
		sum[i]=sum[i-1]+cha;
		b[i]=b[i-1]+sum[i];
	}
	int l = 1,r = n,ans=0;
	while(l <= r)
	{
		int mid = (l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout <<ans;
	return 0;
}

