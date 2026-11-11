#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e3+9;
int f[N];
ll w[N];
ll ti[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i <= n;i++)
	{
		int x;
		cin >> x;
		int u,v,t1,t2;
		cin >> u >> t1 >> v >> t2;
		if(u>v)
		{
			swap(u,v);
			swap(t1,t2);
		}
		f[u]=v;
		ti[u]=t1;
		ti[v]=t2;
	}
//	for(int i=1;i <= n;i++)
//	{
//		cout << ti[i] <<' '<<ti[f[i]];
//	}
	while(q--)
	{
		int st,en;
		cin >> st >> en;
		if(st>en)
		{
			swap(st,en);
		}
		ll sum=0;
		ll x=st;
		while(x!=en)
		{
			sum+=ti[x]+ti[f[x]];
			x=f[x];
		}
		sum+=w[st]+w[en];
		cout<<sum<<"\n";
	}
	return 0;
}

