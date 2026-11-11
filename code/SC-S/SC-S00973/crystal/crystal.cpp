#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,lz=0,z=0; cin>>n>>m;
	a.resize(n);
	for(auto &x:a) cin>>x;
	sort(a.begin(),a.end());
	deque<int> dq;
	for(int y=0;y<n;)
	{
		if(dq.size()==0)
			dq.push_back(a[y++]);
		else if(lz+(int)dq.size()*(a[y]-dq.back())<=m)
		{
			lz+=dq.size()*(a[y]-dq.back());
			dq.push_back(a[y++]);
			z=max(z,(int)dq.size());
		}
		else if(dq.size())
		{
			lz-=(dq.back()-dq.front());
			dq.pop_front();
		}
		z=max(z,(int)dq.size());
	}
	cout<<z;
	cout<<'\n';
	return 0;
}