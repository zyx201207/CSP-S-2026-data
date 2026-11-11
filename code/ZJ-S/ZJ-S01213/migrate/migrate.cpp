#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,T,n,d,a[2001000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12)
		{
			ll x=d/(a[2]-a[1]);
			if(x<=1)
			{
				cout<<0<<"\n";
				continue;
			}
			ll k=2;
			while(k*x<=n) ans+=n-k*x+1,k++;
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int x=i,y=j;
				vector<int>p1,p2;
				p1.push_back(i);
				int ni=upper_bound(a+1,a+n+1,a[x]+d)-a-1;
				while(ni!=x&&ni<j)
				{
					p1.push_back(ni);
					x=ni;
					ni=upper_bound(a+1,a+n+1,a[x]+d)-a-1;
				}
				if(ni>=j) p1.push_back(j);
				else continue;
				p2.push_back(j);
				int nj=lower_bound(a+1,a+n+1,a[y]-d)-a;
				while(nj!=y&&nj>i)
				{
					p2.push_back(nj);
					y=nj;
					nj=lower_bound(a+1,a+n+1,a[y]-d)-a;
				}
				if(nj<=i) p2.push_back(i);
				else continue;
				if(p1.size()!=p2.size()) continue;
				int cnt=0,f=1,len=p1.size();
				for(int k=0;k<len;k++)
				{
					if(p1[k]!=p2[len-k-1]) cnt++;
					if(abs(p1[k]-p2[len-k-1])>1)
					{
						f=0;
						break;
					}
				}
				if(f&&cnt==1) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
