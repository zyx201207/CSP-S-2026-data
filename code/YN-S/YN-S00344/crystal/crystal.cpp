#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],d[N],ans1,ans2,ans,tot=1,maxn;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2,now,tot=k,cnt=1,flag=1;
		now=a[mid];
		for(int i=mid-1;i>=1;i--)
		{
			int d=now-a[i];
			if(tot>=d)
			{
				tot-=d;
				cnt++;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(cnt>=ans) l=mid+1,ans=cnt;
		else r=mid-1;
	}
	cout<<ans<<"\n";
//	for(int i=1;i<=n;i++)
//	{
//		d[i]=a[i+1]-a[i];
//	}
//	
	
	return 0;
}