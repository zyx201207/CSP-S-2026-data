#include<bits/stdc++.h>
using namespace std;

using ll=long long;
ll d[600000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	sort(d+0,d+n);
	int right=n-1;
	vector<ll> res;
	while(right--)
	{
		ll maxn=d[right];
		ll ans=0;
		ll cnt=0;
		for(int i=right;i>=0;i--)
		{
			ans+=(maxn-d[i]);
			if(ans>m)
				break;
			cnt++;
		}
		res.push_back(cnt);
	}
	sort(res.begin(),res.end());
	cout<<res.back()<<endl;
	return 0;
}
