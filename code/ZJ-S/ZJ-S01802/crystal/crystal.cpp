#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int n,ans;
long long m;
long long a[N],b[N],pre[N],back[N];
bool check(int x)
{
	if (x==1)
		return true;
	for (int i=x-1;i<n;i++)
		if (pre[i]-pre[i-x+1]-(x-1)*back[i+1]<=m)
			return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
	for (int i=n-1;i>=1;i--)
		back[i]=back[i+1]+b[i];
	for (int i=1;i<n;i++)
		pre[i]=pre[i-1]+back[i];
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans<<"\n";
	return 0;
} 
