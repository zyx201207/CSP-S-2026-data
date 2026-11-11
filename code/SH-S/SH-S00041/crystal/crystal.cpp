#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
int pre1[500005],pre2[500005],pre3[500005],prei=0;
int ans=0;
int sum(int mid,int i)
{
	return pre1[mid]+pre2[i]+(i-1)*pre3[mid]-pre1[n];
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++)
	{
		prei+=(i-1)*(a[i]-a[i-1]);
		pre1[i]=prei;
	}
	prei=0;
	for(int i=n;i>=1;i--)
	{
		prei+=a[n]-a[i];
		pre2[i]=prei;
	}
	prei=0;
	for(int i=n;i>=1;i--) pre3[i]=a[n]-a[i];
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n+1,mid;
		while(l+1!=r)
		{
			mid=(l+r)/2;
			if(sum(mid,i)>m) r=mid;
			else l=mid;
		}
		ans=max(ans,l-i+1);
	}
	cout << ans;
	return 0;
} 
