#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],n,m,s[N],MAX;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i+1,mid;
		while(l+1<r)
		{
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)r=mid;
			else l=mid;
		}
		MAX=max(MAX,i-r+1);
	}
	cout<<MAX<<endl;
	return 0;
}
