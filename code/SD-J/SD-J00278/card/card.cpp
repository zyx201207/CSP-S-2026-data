#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=5e5+10;
int a[N],b[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	map<int,int> scc;
	int cnt=0;
	for(int i = 1; i<=n; i++)
	{
		cin>>a[i];
		if(scc[a[i]])
		{
			continue;
		}
		scc[a[i]]=1;
		b[++cnt]=a[i];
	}
	int ans=0;
	map<int,int> sl;
	for(int i = 1; i<=n; i++)
	{
		map<int,int> mp;
		map<int,int> w;
		for(int j = i; j<=n; j++)
		{
			if(mp[a[j]]==0)
			{
				mp[a[j]]=1;
				w[a[j]]=j;
				continue;
			}
			int k=w[a[j]];
			for(int x=k; x<j; x++)
			{
				mp[x]=0;
			}
			w[a[j]]=j;
			mp[a[j]]=1;
		}
		for(int j=1; j<=cnt; j++)
		{
			if(mp[b[j]])
			{
			//	cout<<i<<" "<<j<<" "<<b[j]<<endl;
				sl[b[j]]++;
				
			}
		}
	}
	for(int i = 1; i<=cnt; i++)
	{
		if(!scc[b[i]])
			continue;
		cout<<sl[b[i]]<<" ";
	}
	return 0;
}
