#include <iostream>
#include <algorithm> 
using namespace std;
long long a[500005],he[500005];
int n;
long long m;
bool check(int l,int r)
{
	long long x=(r-l+1)*a[r]-(he[r]-he[l-1]);
	if(x<=m)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		he[i]=he[i-1]+a[i];
	}
	int ans=0;
	int ansl,ansr;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		int ans1=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(i,mid))
			{
				l=mid+1;
				ans1=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		ans=max(ans,ans1-i+1);
	}
	cout << ans << endl;
	return 0;
}
