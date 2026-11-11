#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long _,n,m,k,d,q,u,vl,a[505][505],di[505][505],w[N],ans;
vector<pair<long long,long long> > va[500005];
int main(){
	freopen("subway.in","r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);//cout.tie(0);
	cin>>_>>m>>n>>d>>q;
	for(int i = 1;i<=n;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=m;i++){
		cin>>k;
		for(int j = 1;j<=k;j++){
			cin>>u>>vl;
			for(auto x:va[u]){
				int nw=x.second+vl;
				if(nw<a[i][x.first]||a[i][x.first]==0){
					a[i][x.first]=nw;
					a[x.first][i]=nw;
				}
			}
			va[u].push_back({i,vl});
		}
	}
	
	for(int k = 1;k<=m;k++)
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=m;j++){
			if(a[i][k]==0||a[k][j]==0)continue;
			long long nw=a[i][k]+a[k][j];
			if(nw<a[i][j]||a[i][j]==0){
				a[i][j]=nw;
				a[j][i]=nw;
			}
		}
	}
	for(int i = 1;i<=m;i++){
		a[i][i]=0;
	}
	for(int i = 1,qq,qqq;i<=q;i++){
		cin>>qq>>qqq;
		long long ans=9e18;
		for(auto x:va[qq]){
			for(auto y:va[qqq]){
				long long nw=x.second+y.second+a[x.first][y.first];
				if(nw<ans){
					ans=nw;
				}
			}
		}
		cout<<ans+w[qq]+w[qqq]<<"\n";
	}
	return 0;
}

