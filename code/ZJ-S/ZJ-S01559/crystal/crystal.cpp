//bqq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[500010];
int s[500010];
int n,m;
inline int maomao(int x)
{
	int l=1,r=x-1;
	int ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(s[x-1]-s[mid-1]+m>=a[x]*(x-mid)) r=mid-1,ans=x-mid+1;
		else l=mid+1;
	}
	return ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++) ans=max(ans,maomao(i));
	cout<<ans<<endl;
	return 0;
}
