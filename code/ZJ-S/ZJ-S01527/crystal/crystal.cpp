#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int maxn=5e5+10;
int a[maxn],b[maxn];
int ans=0;
int f1=1,f2=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    fast;
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=i) f1=0;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f2=0;
	}
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		for(int i=n;i>=1;i--)
		{
			int mm=m;
			int ans1=0;
	   		for(int j=1;j<=i;j++) b[j]=abs(a[j]-a[i]);
			for(int j=i;j>=1;j--)
			{
				if(b[j]<=mm)
				{
					mm-=b[j];
					ans1++;
				}
			}
			ans=max(ans,ans1);
		}
		cout<<ans;
	}
	else
	{
		if(f1==1)
		{
			if(n*(n+1)<=2*m) 
			{
				cout<<n;
				return 0;
			}
			for(int i=n-1;i>=1;i--)
			{
				if(i*(i+1)<=2*m)
				{
					cout<<i+1;
					return 0;
				}
			}
		}
		else if(f2==1)
		{
			if(n*(a[n]+a[1])<=2*m)
			{
				cout<<n;
				return 0;
			}
			for(int i=n-1;i>=1;i++)
			{
				if(i*(a[1]+a[n])<=2*m)
				{
					cout<<i+1;
					return 0;
				}
			}
		}
		else cout<<n;
	}

}
/*
8

-3 -1 2 2 7
5 3 0 0 5

5
1 2 4 8 9
3 2 0 4 5


*/
