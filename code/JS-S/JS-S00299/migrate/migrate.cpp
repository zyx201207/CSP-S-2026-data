#include<bits/stdc++.h>
using namespace std;
struct poi{
	long long bi,st;
}q[100005];
long long hh,tt;
long long p[100005];
long long pd(long long l,long long r,long long di)
{
	if(r-l<=2) return 0;
	long long mi=0,ans=0;
	hh=tt=l;
	poi s;
	s.bi=l;s.st=0;
	q[l]=s;
	while(hh<=tt) 
	{
		poi now=q[hh];hh++;
		if(now.bi==r)
		{
			if(mi==0) mi=now.st;
			if(now.st==mi) ans++;
			if(now.st>mi) break; 
			continue;
		}
		long long add;
		add=now.bi+1;
		while(p[now.bi]+di>=p[add]&&add<=r)
		{
			poi lin;
			lin.bi=add;
			lin.st=now.st+1;
			tt++;
			q[tt]=lin;
			add++;
		}
	}
	if(ans==2) return 1;
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,T;
	cin>>c>>T;
	while(T--)
	{
		long long n,d;
		long long res=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>p[i];
		for(long long l1=1;l1<=n;l1++)
			for(long long r1=l1;r1<=n;r1++)
			{
				res+=pd(l1,r1,d);
			}
		cout<<res<<endl;
	}
	return 0;
}
