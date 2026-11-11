#include<bits/stdc++.h>
using namespace std;
long long inf=1e18;
vector< pair<int,long long> > s[500015];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	vector<long long> w(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			long long a,t;
			cin>>a>>t;
			s[a].push_back({i,t});
		}
	}
	vector <vector <long long> > d(n+1,vector <long long> (n+1,inf));
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int v=1;v<=m;v++)
	{
		int sz=s[v].size();
		for(int i=0;i<sz;i++)
		{
			for(int j=i+1;j<sz;j++)
			{
				int l1=s[v][i].first;
				long long t1=s[v][i].second;
				int l2=s[v][j].first;
				long long t2=s[v][j].second;
				long long c=t1+t2;
				if(c<d[l1][l2])
				{
					d[l1][l2]=c;
					d[l2][l1]=c;
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i][k]==inf) continue;
			for(int j=1;j<=n;j++)
			{
				if(d[i][k]+d[k][j]<=d[i][j]) d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
	for(int r=0;r<q;r++)
	{
		int x,y;
		cin>>x>>y;
		long long ans=inf;
		for(size_t idx1=0;idx1<s[x].size();idx1++)
		{
			pair <int,long long> p1=s[x][idx1];
			int l1=p1.first;
			long long t1=p1.second;
			for(size_t idx2=0;idx2<s[y].size();idx2++)
			{
				pair <int,long long> p2=s[y][idx2];
				int l2=p2.first;
				long long t2=p2.second;
				if(d[l1][l2] != inf)
				{
					long long cc=w[x]+t1+d[l1][l2]+t2+w[y];
					ans=min(ans,cc);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
