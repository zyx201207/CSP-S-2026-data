#include<bits/stdc++.h>
using namespace std;
long long ccccs,n,m,d,q;
long long ww[250005];
long long dx[505][250005];
long long vis[250005];
vector<pair<long long,long long> > ve[250005];
priority_queue< pair<long long,long long> > qu;
long long dij(long long uu,long long vv)
{
	pair <long long,long long> ba;
	ba.first=0;
	ba.second=uu;
	qu.push(ba);
	
	for (int i=0;i<=250000;i++)
	{
//		cout<<i<<" ";
		vis[i]=0;
	}
	vis[uu]=1;
//	vis[6]=0;
//	cout<<vis[6]<<"\n";
	while (!qu.empty())
	{
		
		long long u=qu.top().second;
		long long w=qu.top().first;
		qu.pop();
	//	cout<<u<<" "<<w<<"\n";
		if (u==vv)
		{

			while (!qu.empty()) qu.pop();
			return w;
		}
		for (int i=0;i<ve[u].size();i++)
		{
			long long v=ve[u][i].first;
	//		cout<<vis[v]<<" "<<v<<"\n";
			if (vis[v]==0)
			{
				vis[v]=1;
				pair <long long,long long> hh;
				hh.first=w+ve[u][i].second;
				hh.second=v;
				qu.push(hh);
			}
		}
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>ccccs>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>ww[i];
	}
	for (int i=1;i<=n;i++)
	{
		long long k=0,shang=0;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			long long aaa=0,bbb=0;
			cin>>aaa>>bbb;
			aaa+=i*m;
			dx[i][aaa%m]=bbb;
			if (shang==0) shang=aaa;
			else
			{
				ve[shang].push_back({aaa,0});
				ve[aaa].push_back({shang,0});
				shang=aaa;
			}
		}
		
		
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<n;j++)
		{
			for (int k=j+1;k<=n;k++)
			{
				long long ddne=i+m*j;
				long long ddtw=i+m*k; 
				if (ve[ddne].size()!=0&&ve[ddtw].size()!=0)
				{
					ve[ddne].push_back({ddtw,dx[k][i%m]+dx[j][i%m]});
					ve[ddtw].push_back({ddne,dx[k][i%m]+dx[j][i%m]});
				}
			}
		}
	}
	for (int i=1;i<=m;i++)//2
	{
		for (int j=1;j<=n;j++)//1
		{
			long long ddne=i+m*j;//7
			if (ve[ddne].size()!=0)
			{
				ve[ddne].push_back({i,ww[i]+dx[j][i%m]});
				ve[i].push_back({ddne,ww[i]+dx[j][i%m]});
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		long long ua,vb;
		cin>>ua>>vb;
		cout<<dij(ua,vb)<<"\n";
	}
	return 0;
} 