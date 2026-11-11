#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,l=1,r;
vector<long long> a,p;
inline long long c(long long i,long long j)
{
	return p[j]-(p[i]+i*(a[j]-a[i+1]));
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	p.push_back(0);
	p.push_back(0);
	a.push_back(0);
	for(long long i=1,tmp;i<=n;i++)
	{
		cin>>tmp;
		a.push_back(tmp);
	}
	sort(a.begin(),a.end());
	for(int i=2;i<=n;i++)
		p.push_back(p.back()+(i-1)*(a[i]-a[i-1]));
	r=ans=upper_bound(p.begin(),p.end(),m)-p.begin()-1;
	while(r<=n)
	{
		
		l=r-ans+1;
		while(c(l,r)<=m&&l>=1)
			l--;
		r++;
		if(c(l,r-1)>m)
		{
			ans=max(ans,r-l-3);
			continue;
		}
		ans=max(ans,r-l-1);
	}
	cout<<ans;
	return 0;
}