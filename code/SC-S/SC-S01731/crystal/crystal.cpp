#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=5e5+10;

int n,ans; ll m,p[N],s[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>p[i];
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+p[i];
	for(int i=1,j=1;i<=n;++i)
	{
		while(p[i]*(i-j+1)-(s[i]-s[j-1])>m) ++j;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}