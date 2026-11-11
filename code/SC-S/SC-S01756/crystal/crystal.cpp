#include<iostream>
#include<algorithm>
using namespace std;
#define int long long 
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		a[i]+=a[i-1];
	int l=1;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		int x=a[i]-a[i-1],y=a[i-1]-a[l-1];
		while(x*(i-l)-y>m)
		{
			y-=(a[l]-a[l-1]);
			l++;
		}
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn;
	
		
		
} 