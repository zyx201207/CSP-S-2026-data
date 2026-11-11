#include <bits/stdc++.h>
using namespace std;

int m,n;
long long a[1000000];
long long dp(int z,int s);
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long ans(0);
	cin >> n >> m;
	
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==n)
	{
		ans=a[1];
		for(int i = 2;i<=n;i++)
		{
			ans=ans&&a[i];
		}	
		cout << ans << endl;
		return 0;
	}
	
	for(int i = 1;i<=n;i++)
	{
		int h;
		h=a[i];
		a[i]=-1;
		ans=max(ans,dp(h,1));
		a[i]=1;
	}
		cout << ans;
	return 0;
 } 
long long dp(int z,int s)
 {
 	//cout << z << " " << s << " " << endl;
 	if(s==m)
 	{
 		return z;
	 }
 	long long mm=0;
 	for(int i = 1;i<=n;i++)
 	{
 		if(a[i]==-1)
 		{
 			continue;
		 }
		 int hh=a[i];
		a[i]=-1;
		mm=max(mm,dp(z&&hh,s+1));
		a[i]=1;
	 }
	 return mm;
 }