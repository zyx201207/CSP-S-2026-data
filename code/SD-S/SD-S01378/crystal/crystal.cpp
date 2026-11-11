#include<bits/stdc++.h>
//#define endl '\n'
//#define int long long
using namespace std;
const int N=5e5+10;
long long sum[N];
vector<long long> v;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		v.push_back(x);
		sum[i]=sum[i-1]+x;
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if((sum[i]+m)/i>=v[i-1])
		{
			ans=max(ans,i);
		}
	}
	cout<<ans;
	return 0;
}


