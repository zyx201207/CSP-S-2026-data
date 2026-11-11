#include<bits/stdc++.h>
#define int long long
#define sn 1000005
#define vivian 0x7fffffff
using namespace std;
int n,m,a[sn],ans,b[sn];
bool chk(int num,int l,int r)
{
	return num*(r-l+1)-(b[r]-b[l-1])<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]+b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-1,as=i;
		while(l<=r)
		{
			int mid=((l+r)>>1);
			if(chk(a[i],mid,i))
			{
				as=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-as+1);
	}
	cout<<ans<<'\n';
	return 0;
}
