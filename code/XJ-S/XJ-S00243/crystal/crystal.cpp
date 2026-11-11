#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN=5e5+100;
int n;
ll m,a[MAXN];
int ans=0;
bool check(int x)
{
	ll sum=0;
	for(int i=1;i<x;i++)sum+=a[i];
	for(int i=1,j=i+x-1;j<=n;i++,j++)
	{
		sum=sum-a[i-1]+a[j];
		ll mx=a[j];
		if(mx*x-sum<=m)return 1;
	}
	return 0;
}
int search()
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<search();
	return 0;
}
