#include <bits/stdc++.h>
//++rp
typedef long long ll;
using namespace std;
int main() 
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> u(n+5),v(n+5);
		int ans=0;
		for(int i=1;i<=n;++i) cin>>u[i]>>v[i];
		int minn=INT_MAX;
		map<int,int> mp;
		for(int i=0;i<n;++i) mp[u[i]]++;
		for(auto i:mp) minn=min(minn,i.second);
		ans=minn;
		cout<<ans<<"\n";
	}
	return 0;
}
//树+连通块
//难度估计:提高+/省选-
//special:10pts simple:90pts
//预估分数:special(0)+simple骗分(?)=?