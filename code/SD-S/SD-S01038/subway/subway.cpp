#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int k[505];
long long w[500005];
long long c[505][505];
vector<long long> a[505],t[505];
vector<pair<int,int> > hd[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int tp,n,m,d,q;
	cin>>tp>>n>>m>>d>>q;
	memset(c,0x3f,sizeof c);
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		c[i][i]=0;
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			hd[aa].push_back({i,j});
		}
	}
	for(int i=1;i<=m;++i){
		int len=hd[i].size();
		int u,opu;
		int v,opv;
		for(int j=0;j<len;++j){
			for(int k=j+1;k<len;++k){
				u=hd[i][j].first,opu=hd[i][j].second;
				v=hd[i][k].first,opv=hd[i][k].second;
				c[u][v]=c[v][u]=min(c[v][u],t[u][opu-1]+t[v][opv-1]);
			}
		}
	} 
	for(int i=1;i<=n;++i){
		for(int k=1;k<=n;++k){
			for(int j=1;j<=n;++j){
				c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
			}
		}
	}
	for(int ttt=1;ttt<=q;++ttt){
		int u,v;
		cin>>u>>v;
		int len1=hd[u].size();
		int len2=hd[v].size();
		long long ans=0x3f3f3f3f3f3f3f3f;
		int opu,opv;
		for(int i=0;i<len1;++i){
			for(int j=0;j<len2;++j){
				opu=hd[u][i].second;
				opv=hd[v][j].second;
				ans=min(ans,c[hd[u][i].first][hd[v][j].first]+t[hd[u][i].first][opu-1]+t[hd[v][j].first][opv-1]);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
