#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define P(x,y) make_pair(x,y)
#define c(x) cout<<#x<<"="<<x<<endl;
using namespace std;
const int inf=1e9;
const int N=5e5+10;
int a[N],s[N];
int n,m;


signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1]) continue;
		int l=1,r=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
