#include<bits/stdc++.h>
using namespace std;
const int N=509,M=5e5+9;
int c,n,m,dd,q,x[N],l[M],k[N];
long long d[N][N];
vector<pair<int,int> > vp[M];
int main(){
#ifndef DEBUG
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++){
		cin>>l[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,x;
			cin>>a>>x;
			vp[a].push_back(
				make_pair(
					i,x
				));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		d[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vp[i].size();j++){
			for(int k=j+1;k<vp[i].size();k++){
				int pj=vp[i][j].first;
				int pk=vp[i][k].first;
				long long kj=vp[i][j].second;
				long long kk=vp[i][k].second;
				d[pk][pj]=d[pj][pk]=min(d[pj][pk],kj+kk);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
#ifdef DEBUG
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
#endif
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int j=0;j<vp[x].size();j++){
			for(int k=0;k<vp[y].size();k++){
				int pj=vp[x][j].first;
				int pk=vp[y][k].first;
				int kj=vp[x][j].second;
				int kk=vp[y][k].second;
				ans=min(ans,kj+kk+d[pj][pk]);
			}
		}
		cout<<ans+l[x]+l[y]<<endl;
	}
	return 0;
}
