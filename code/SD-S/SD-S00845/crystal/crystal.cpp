#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=0x3f3f3f3f3f3f;
int n,m,a[500005],ans=0,c[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int mina=MAXN;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) c[i]=a[i]-a[i-1];
	int l=1,r=1,sum=0;
	while(l<=r&&l<=n&&r<=n)
	{
		sum+=c[r]*(r-l);
		while(sum>m)
		{
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
 } 
