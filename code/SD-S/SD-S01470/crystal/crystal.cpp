#include<bits/stdc++.h>
#define int long long

namespace Crystal
{
using namespace std;

const int N=5e5+10;
int n,m;
int a[N];
int s[N];
int ans=0;

void input()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
}

void solve()
{
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)s[i]=s[i-1]+a[i];

	auto check=[&](int x)
	{
		int minn=INT_MAX;
		for(int i=1; i+x-1<=n; i++)
		{
			int cnt=0;
//			for(int j=1; j<x; j++)
//			{
//				cnt+=j*d[i+j];
//			}
			int j=i+x-1;
			cnt=(x-1)*a[j]-(s[j-1]-s[i-1]);
			minn=min(minn,cnt);
		}
		if(minn>m)return false;
		else return true;
	};

	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
}

void output()
{
	cout<<ans<<endl;
}

int main()
{
	input();
	solve();
	output();
	return 0;
}
}

signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	Crystal::main();
	return 0;
}
