#include<bits/stdc++.h>
using namespace std;
namespace Subway{
	const int MAXN=505;
	const int MAXM=5e5+10;
	int c,n,m,d,q;
	long long w[MAXM];
	long long dis[1005][1005];
	struct node{
		long long a,t;
	};
	vector<node> mp[MAXN];
	int k[MAXN];
	struct edge{
		long long v,w;
	};
	vector<edge> e[MAXM];
	void work(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++)
			cin>>w[i];
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j)
					dis[i][j]=0;
				else
					dis[i][j]=INT_MAX;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int a,t;
				cin>>a>>t;
				mp[i].push_back({a,t});
			}
			for(int j=0;j<k[i]-1;j++){
				for(int h=j+1;h<k[i];h++){
					e[mp[i][j].a].push_back({mp[i][h].a,mp[i][j].t+mp[i][h].t});
					e[mp[i][h].a].push_back({mp[i][j].a,mp[i][j].t+mp[i][h].t});
					dis[mp[i][j].a][mp[i][h].a]=min(dis[mp[i][j].a][mp[i][h].a],mp[i][j].t+mp[i][h].t);
					dis[mp[i][h].a][mp[i][j].a]=min(dis[mp[i][h].a][mp[i][j].a],mp[i][j].t+mp[i][h].t);
			//		cout<<mp[i][j].a<<"->"<<mp[i][h].a<<":"<<dis[mp[i][j].a][mp[i][h].a]<<"\n";
				}
			}
		}
		for(int kk=1;kk<=m;kk++)
			for(int i=1;i<=m;i++)
				for(int j=1;j<=m;j++)
					dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
		for(int i=1;i<=m;i++){
			
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<"\n";
		}
		return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Subway::work();
	return 0;
}
