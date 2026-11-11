#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[510][510];
vector<pair<int,int>>t[500010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,num,time;
		cin>>k;
		for(int id=1;id<=k;id++)
		{
			cin>>num>>time;
			t[num].push_back({i,time});
		}
	}
	memset(a,0x3f,sizeof(a));
	for(int id=1;id<=m;id++)
	{
		for(unsigned int i1=0;i1<t[id].size();i1++)
		{
			for(unsigned int i2=i1+1;i2<t[id].size();i2++)
			{
				int p1=t[id][i1].first,t1=t[id][i1].second;
				int p2=t[id][i2].first,t2=t[id][i2].second;
				a[p1][p2]=min(a[p1][p2],t1+t2);
				a[p2][p1]=min(a[p2][p1],t1+t2);
			}
		}
	}
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	int ss,tt,ans;
	while(q--)
	{
		cin>>ss>>tt;
		ans=1e18;
		for(unsigned int si=0;si<t[ss].size();si++)
		{
			for(unsigned int ti=0;ti<t[tt].size();ti++)
			{
				ans=min(ans,a[t[ss][si].first][t[tt][ti].first]+t[ss][si].second+t[tt][ti].second+w[ss]+w[tt]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
