#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int id,n,m,d,q;
int a[500005];
vector<pair<int,int> > v[500005];
int c[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>id>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	memset(c,0x3f,sizeof c);
	for(int i=1; i<=n; i++) c[i][i]=0;
	for(int i=1; i<=m; i++){
		int tr=v[i].size();
		for(int j=0;j<tr;j++){
			for(int k=j+1;k<tr;k++){
				int u=v[i][j].first,to=v[i][k].first,w=v[i][j].second+v[i][k].second;
				c[u][to]=min(c[u][to],w);
				c[to][u]=min(c[to][u],w);
			}
		}
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(pair<int,int> i:v[x]){
			for(pair<int,int> j:v[y]){
				int u=i.first,to=j.first;
				ans=min(ans,i.second+j.second+c[u][to]);
			}
		}
		cout<<a[x]+a[y]+ans<<"\n";
	}
	return 0;
}
