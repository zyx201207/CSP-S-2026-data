#include<bits/stdc++.h>
#define lltt long long
using namespace std;
const lltt inf=1e18;
int n;
lltt m;
lltt a[500005],s[500005];
map<lltt,int>cnt;
bool check(int l,int r)
{
	if(a[r]*(r-l)-s[r-1]+s[l-1]<=m)
		return true;
	return false;
} 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cnt[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	a[0]=inf;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1])
		{
			int l=1,r=i-1;
			int res=i;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(check(mid,i))
				{
					res=mid;
					r=mid-1;
				}
				else
					l=mid+1;
			}
			ans=max(ans,i-res+cnt[a[i]]);
		}
	cout<<ans<<"\n";
	return 0;
}
