#include<iostream>
#include<vector>
using namespace std;
int tc,n,m,g,q,nn,sr1,sr2,w[500010];
long long f[510][510],d;
vector<pair<int,int>> b[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>tc>>n>>m>>g>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>nn;
		for(int j=1;j<=nn;j++){
			cin>>sr1>>sr2;
			b[sr1].push_back({i,sr2});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				f[i][j]=1e18;
	for(int i=1;i<=m;i++)
		for(int j1=0;j1<b[i].size();j1++)
			for(int j2=j1+1;j2<b[i].size();j2++){
				f[b[i][j1].first][b[i][j2].first]=min(f[b[i][j1].first][b[i][j2].first],0ll+b[i][j1].second+b[i][j2].second);
				f[b[i][j2].first][b[i][j1].first]=min(f[b[i][j2].first][b[i][j1].first],0ll+b[i][j1].second+b[i][j2].second);
			}
	for(int i=1;i<=n;i++)
		for(int j1=1;j1<=n;j1++)
			for(int j2=1;j2<=n;j2++)
				f[j1][j2]=min(f[j1][j2],f[j1][i]+f[i][j2]);
	for(int i=1;i<=q;i++){
		cin>>sr1>>sr2;
		d=1e18;
		for(auto j1:b[sr1])
			for(auto j2:b[sr2])
				d=min(d,f[j1.first][j2.first]+j1.second+j2.second);
		cout<<d+w[sr1]+w[sr2]<<'\n';
	}
}
