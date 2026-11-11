#include<bits/stdc++.h>
using namespace std;
long long a[200005];
vector<long long> v;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		v.push_back(a[i]);
	}
	long long ans=0;
	for(long long i=30;i>=0;i--)
	{
		vector<long long> tmp;
		for(auto it:v)
		{
			if((it>>i)&1) tmp.push_back(it);
		}
		if(tmp.size()>=m)
		{
			v=tmp;
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
