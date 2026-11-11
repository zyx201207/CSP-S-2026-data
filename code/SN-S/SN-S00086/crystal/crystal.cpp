#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m;
int a[500005];
int ans=1;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	int len=1;
	int sum=m;
	while(1)
	{
		if(r==n) break;
		while(a[r+1]==a[r])
		{
			r++;
			len++;
		}
		while(len*(a[r+1]-a[r])<=sum)
		{
			if(r==n) break;
			sum-=len*(a[r+1]-a[r]);
			len++;
			r++;
		}
//		cout<<l<<" "<<r<<" "<<len<<" "<<sum<<"\n\n";
		sum+=a[r]-a[l];
		if(l==r)
		{
			l++;
			r++;
		}
		l++;
		ans=max(ans,len);
		len--;
	}
	cout<<ans;
	return 0;
}
