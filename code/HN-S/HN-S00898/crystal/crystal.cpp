#include <bits/stdc++.h>

namespace solve
{
	int n;
	long long m;
	std::vector<long long> a,pre;
	long long sum(int l,int r){return l?pre[r]-pre[l-1]:pre[r];}
	void main()
	{
		std::cin>>n>>m;
		a.resize(n);
		pre.resize(n);
		for(int i=0;i<n;i++)
			std::cin>>a[i];
		std::sort(a.begin(),a.end());
		std::partial_sum(a.begin(),a.end(),pre.begin());
		int ans=1;
		for(int i=0;i<n;i++)
		{
			int l=0,r=i,mid,res=1;
			while(l<=r)
			{
				mid=(l+r)/2;
				if((i-mid+1)*a[i]-sum(mid,i)<=m)
					res=mid,r=mid-1;
				else l=mid+1;
			}
			ans=std::max(i-res+1,ans);
		}
		std::cout<<ans;
	}
}

int main()
{
using namespace std;
#define PROBLEM "crystal"
#if 1
	freopen(PROBLEM".in","r",stdin);
	freopen(PROBLEM".out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve::main();
	return 0;
}