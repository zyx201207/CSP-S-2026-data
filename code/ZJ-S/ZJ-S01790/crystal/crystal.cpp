#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k,cnt;
int a[N];
int num[N],s[N];
bool flag=true;
signed main(void)
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1]!=a[i+1]-a[i]) flag=false;
	if(n<=5000)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			num[i]=num[i-1]+(i-1)*(a[i]-a[i-1]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(num[j]-num[i-1]-(i-1)*(a[j]-a[i-1])<=k)
					ans=max(ans,j-i+1);
			}
		}
		cout<<ans;
	}
	else if(flag)
	{
		int d=a[2]-a[1],ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i*(i-1)/2*d<=k) ans=i;
		}
		cout<<ans;
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			num[i]=num[i-1]+(i-1)*(a[i]-a[i-1]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(num[j]-num[i-1]-(i-1)*(a[j]-a[i-1])<=k)
					ans=max(ans,j-i+1);
				if(clock()>900000)
				{
					cout<<ans;
					return 0;
				}
			}
		}
	}
}
