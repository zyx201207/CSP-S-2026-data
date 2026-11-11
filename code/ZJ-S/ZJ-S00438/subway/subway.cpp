#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
vector<pair<int,int> >a[N];
int gunmugunmu,n,m,d,q,cost[N],len[N],f[600][600];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>gunmugunmu>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=-1;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)cin>>cost[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int noow,t;
			cin>>noow>>t;
			a[noow].push_back(make_pair(i,t));len[noow]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<len[i];j++)
		{
			for(int k=j+1;k<len[i];k++)
			{
				f[a[i][j].first][a[i][k].first]=(f[a[i][j].first][a[i][k].first]==-1)?a[i][j].second+a[i][k].second:min(f[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
				f[a[i][k].first][a[i][j].first]=(f[a[i][j].first][a[i][k].first]==-1)?a[i][j].second+a[i][k].second:min(f[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if((f[i][j]>f[i][k]+f[k][j]||f[i][j]==-1)&&f[i][k]!=-1&&f[k][j]!=-1)f[i][j]=f[i][k]+f[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int st,lst,ans=-1;
		cin>>st>>lst;
		for(int j=0;j<len[st];j++)
		{
			for(int k=0;k<len[lst];k++)
			{
				if(f[a[st][j].first][a[lst][k].first]==-1)continue;
				ans=(ans==-1)?f[a[st][j].first][a[lst][k].first]+a[st][j].second+a[lst][k].second:min(ans,f[a[st][j].first][a[lst][k].first]+a[st][j].second+a[lst][k].second);
			}
		}
		cout<<ans+cost[st]+cost[lst]<<endl;
	}
	return 0;
}