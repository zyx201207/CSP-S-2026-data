/*It's Not Until You Fall That You Fly*/
/*RP++*/
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a1,a2,t1,t2;
vector<int>mp[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a2>>t2;
			if(j>1)
			{
				mp[a2].push_back(a1);
			}
			if(j<n)
			{
				mp[a1].push_back(a2);
			}
			a2=a1;
			t2=t1;
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		long long int ans;
		ans=w[u]+w[v];
		cout<<ans<<endl;
	}
	return 0;
}
