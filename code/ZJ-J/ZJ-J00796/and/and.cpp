#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m;
ll a[N];
ll shu[N];
vector<ll> v[100];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=30;j>=1;j--)
		{
			if(a[i]&(1ll<<(j-1)))
			{
				v[j].push_back(a[i]);
			}
		}
	}
	int k;
	for(int i=30;i>=1;i--)
	{
		if(v[i].size()>=m)
		{
			k=i;
			break;
		}
	}
	ll ans=(1ll<<(k-1));
	for(int i=k-1;i>=1;i--)
	{
		ll sum=0;
		for(int j=0;j<v[k].size();j++)
		{
			if(v[k][j]&(1ll<<(i-1)))
			{
				sum++;
				if(sum>=k)break;
			}
		}
		if(sum>=m)ans+=(1ll<<(i-1));
	}
	cout<<ans;
	return 0;
}

