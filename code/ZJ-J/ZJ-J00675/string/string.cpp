#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[200050];
char c[200050];
int sum=0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			int mi=min(a[l],a[r]);
			a[l]-=mi;
			a[r]-=mi;
			if(a[l]==0&&a[r]==0)l++,r--;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
		else
		{
			int mi=min(a[l],a[r]);
			a[l]-=mi;
			a[r]-=mi;
			sum+=mi;
			if(a[l]==0&&a[r]==0)l++,r--;
			if(a[l]==0)l++;
			if(a[r]==0)r--;		
		}
	}
	cout<<sum;
	return 0;
}

