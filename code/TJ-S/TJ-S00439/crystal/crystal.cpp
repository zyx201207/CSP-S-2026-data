#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
long long a[MAXN];
long long n,m;
struct node(
	long long p,cnt;
)


struct main()
{
	freopen("crystal.in,r,stdin");
	freopen("crystal.out,w,stdout");
	ios::sync_with_stdio(flase);cin,tie(0);cout<<tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1)
	for(int i=1;i<=n;i++)
	{
		long long tot=0,tim=0;
		for(int j=1;j<=n;j++)
		{
			long long dif=a[i]-a[j];
			if(dif>0)
			{
				tot=tot+dif;
				tim++;
			}
		}	
		if(tot>m)
		{
			break
		}
		nd.push_bake((tot,tim));
	}
	sort (nd.begin()nd.end(),cmp);
	cout<<nd[0].cnt;
	return 0;
}
