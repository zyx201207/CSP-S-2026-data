#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,mm,g[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	mm=m;
	for(int i=1;i<=n;i++) cin>>g[i];
	sort(g+1,g+n+1,greater<int>());
	int now=1;
	for(int i=2;i<=n;i++)
	{
		if(g[1]-g[i]<=m) m-=g[1]-g[i],now++;
		else break;
	}
	ans=now;
	for(int l=2,r=now;l<=n;l++)
	{
		if(r<l) r=l,m=mm;
		else m+=(r-l+1)*(g[l-1]-g[l]);
		while(r<n&&g[l]-g[r+1]<=m) m-=g[l]-g[r+1],r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
