#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=r;i>=l;i--)
#define c1(x) __builtin_popcountll(x)
#define ull unsigned long long
#define lowbit(x) x&-x
#define int long long
#define pb push_back
#define db double

using namespace std;

typedef pair<int,int> pii;
typedef pair<db,db> pdd;

const int N=5e5+10;
int n,m,a[N],sum[N]; 

bool check(int mid)
{
	int ans=1e18;
	rep(i,1,n)
		if(i>=mid) 
			ans=min(ans,mid*a[i]-(sum[i]-sum[i-mid]));
	return ans<=m;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	rep(i,1,n) sum[i]=sum[i-1]+a[i]; 
	int l=1,r=n,ans=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
/*CSP-S 2026 AK RP++!
有没有写freopen?
数组是否开够？
有没有爆空间？
有没有交错代码？
*/

