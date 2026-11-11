#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
int zt[600000];
int k;
vector<pair<int,int> >e[10000];
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>zt[i];
		e[i].push_back({i+500000,zt[i]});
		e[i+500000].push_back({i,zt[i]});
	}
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			
		}
	}
}
