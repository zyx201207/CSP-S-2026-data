#include <bits/stdc++.h>

namespace solve
{
	int n;
	long long d;
	std::vector<long long> a,cntl,cntr,maxl,maxr,resl,resr,suml,sumr;
	std::vector<std::array<int,2>> dp; 
	std::vector<int> pre,suf;
	void main(int _c)
	{
		std::cin>>n>>d;
		a.resize(n);
		dp.assign(n,{1,0});
		cntl.assign(n,0);
		cntr.assign(n,0);
		maxl.assign(n,0);
		maxr.assign(n,0);
		resl.assign(n,0);
		resr.assign(n,0);
		suml.assign(n,0);
		sumr.assign(n,0);
		pre.resize(n);
		suf.resize(n);
		std::iota(pre.begin(),pre.end(),0);
		std::iota(suf.begin(),suf.end(),0);
		for(int i=0;i<n;i++) std::cin>>a[i];
		for(int i=0,j=0;i<n;i++)
		{
			while(j+1<n&&a[j+1]<=a[i]+d) j++;
			suf[i]=j;if(i!=j) cntl[j]++;
		}
		for(int i=n-1,j=n-1;i>=0;i--)
		{
			while(j-1>=0&&a[j-1]+d>=a[i]) j--;
			pre[i]=j;if(i!=j) cntr[j]++;
		}
		for(int i=0;i<n;i++)
		{
			if(pre[i]==i) continue;
			if(suf[pre[i]]==i) maxl[i]=maxl[pre[i]]+1;
		}
		for(int i=n-1;i>=0;i--)
		{
			if(suf[i]==i) continue;
			if(pre[suf[i]]==i) maxr[i]=maxr[suf[i]]+1;
		}
		for(int i=0;i<n;i++)
		{
			resl[i]=std::max(maxl[i]-1,0ll)+cntl[i];
			resr[i]=std::max(maxr[i]-1,0ll)+cntr[i];
			if(suf[i]!=i) suml[suf[i]]+=resl[i]+1;
			if(pre[i]!=i) sumr[pre[i]]+=resr[i]+1;
		}
		long long ans=0;
		for(int i=0;i+1<n;i++)
			ans+=suml[i+1]*sumr[i];
		std::cout<<ans<<'\n';
	}
}

int main()
{
using namespace std;
#define PROBLEM "migrate"
#if 1
	freopen(PROBLEM".in","r",stdin);
	freopen(PROBLEM".out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;std::cin>>c>>T;
	while(T--) solve::main(c);
	return 0;
}