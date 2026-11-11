#include<bits/stdc++.h>
#define int long long
const int N=5e5+10;
using namespace std;
int n,m;
int a[N];
int ans=-1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=1;
		vector<int> b;
		for(int j=1;j<=n;j++)
		{
			if(i==j||a[i]-a[j]<0) continue;
			b.push_back(a[i]-a[j]);
		}
		sort(b.begin(),b.end());
		int t=m;
		for(auto it:b)
		{
			if(t>=it)
			{
				t-=it;
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/
