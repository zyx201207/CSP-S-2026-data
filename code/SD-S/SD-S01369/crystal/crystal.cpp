#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N=5e5+10;
const int inf=0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N],s[N];
int ans;
bool check(int mid,int p)
{
	return a[p]*(p-mid+1)-(s[p]-s[mid-1])<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,res=1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i)) res=i-mid+1,r=mid-1;
			else l=mid+1; 
		}
		ans=max(ans,res);
	}
	cout<<ans; 
	return 0;
}
//Oct31==Dec25?
