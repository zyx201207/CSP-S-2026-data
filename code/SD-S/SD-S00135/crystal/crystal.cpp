#include<bits/stdc++.h>
#define int long long
#define cute_fzj_kuai_ruarua ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int s[N];
bool check(int l,int r)
{
	return a[r]*(r-l+1)-(s[r]-s[l-1])<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cute_fzj_kuai_ruarua;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(i,mid)) l=mid+1,ans=max(ans,mid-i+1);
			else r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
 }

