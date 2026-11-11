#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000101,M=1011;
int n,m,a[N],ans;

bool check (int x)
{
	int sum=0;
	for (int i=1;i<=x;i++) sum=sum+(a[x]-a[i]);
	return sum<=m;
}

signed main ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);cout.tie (0);
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);

	cin >>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	sort (a+1,a+1+n);
	int l=1,r=1,sum=0;
	while (l<n&&r<n)
	{
		r++;
//		sum=0;
		if (a[r]!=a[r-1])
		{
			int cha=a[r]-a[r-1];
			sum=sum+(r-l)*cha;
//			for (int i=l;i<=r;i++) sum=sum+a[r]-a[i];
			if (sum>m) while (sum>m) sum=sum-(a[r]-a[l]),l++;
		}
		ans=max (ans,r-l+1);
//		cout <<l<<" "<<r<<" "<<sum<<"\n";
	}
	cout <<ans;

//	cin >>n>>m;
//	int F=1,FF=1;
//	for (int i=1;i<=n;i++)
//	{
//		cin >>a[i];
//		if (a[i]!=i) F=0;
//		if (i==2) int qwq=a[i]-a[i-1];
//		if (i>2)
//		{
//			if (a[i]-a[i-1]!=qwq) FF=0;
//		}
//	}
//	if (n<=16&&m<=1000)
//	{
//		
//	}
//	else if (F==1)
//	{
//		
//	}
//	else if (FF==1)
//	{
//		
//	}
//	else if
//	{
//		sort (a+1,a+1+n);
//	//	for (int i=1;i<=n;i++) cout <<a[i]<<" ";
//		int l=1,r=n;
//		while (l<=r)
//		{
//			int mid=(l+r)/2;
//			if (check (mid) ) l=mid+1;
//			else r=mid-1;
//		}
//	//	cout <<l;
//		for (int i=1;i<=n;i++)
//			if (a[i]<=a[l-1]) ans++;
//		cout <<ans;
//	}
	
	return 0;
}
