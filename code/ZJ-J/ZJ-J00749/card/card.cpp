#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans[N];
vector<int> mp[N];
signed main()
{
	freopen("card5.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		int t=i;
		while(t<n)
		{
			ans[a[t]]++;
			t=mp[a[t]][mp[a[t]].size()-1]+1;
		}
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}