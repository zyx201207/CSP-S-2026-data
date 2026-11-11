#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int c,n,m,d,q,w[maxn],k,a,t,f[510][510],s;
vector<pair<int,int>> rou[maxn];
signed main()
{
	freopen("subway7.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			rou[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		k=rou[i].size();
		for(int j=0;j<k;j++)
			for(int l=j+1;l<k;l++)
			{
//				cout<<i<<endl;
				auto x=rou[i][j],y=rou[i][l];
//				if(x.first>y.first)swap(x,y);
				f[x.first][y.first]=min(f[x.first][y.first],x.second+y.second);	
				f[y.first][x.first]=f[x.first][y.first];			
			}		
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)cout<<f[i][j]<<' ';
//		cout<<endl;
//	}
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
	while(q--)
	{
		int ans=1e18;
		cin>>s>>t;
		for(auto x:rou[s])
			for(auto y:rou[t])
				ans=min(ans,f[x.first][y.first]+x.second+y.second+w[s]+w[t]);
		cout<<ans<<endl;
	}
	return 0;
}
