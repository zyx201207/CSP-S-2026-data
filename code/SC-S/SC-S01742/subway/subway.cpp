#include<bits/stdc++.h>
using namespace std;
vector<long long>mp[500011];
int c,n,m,d,q;
long long w[500011],p[22][500011],o[511][511];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			o[i][j]=o[j][i]=1e18;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;cin>>a>>b;
			p[mp[a].size()][a]=b;
			mp[a].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){//用地铁站台去松弛地铁线路
		for(int j=0;j<mp[i].size();j++){
			for(int k=j+1;k<mp[i].size();k++){
				o[mp[i][j]][mp[i][k]]=o[mp[i][k]][mp[i][j]]=min(o[mp[i][k]][mp[i][j]],p[j][i]+p[k][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){//用地铁线路去松弛地铁线路
		for(int j=1;j<=n;j++){
			for(int k=i+1;k<=n;k++){
				o[j][k]=o[k][j]=min(o[k][j],o[i][j]+o[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long ans=1e18;int x,y;
		cin>>x>>y;
		for(int j=0;j<mp[x].size();j++){
			for(int u=0;u<mp[y].size();u++){
				ans=min(ans,o[mp[x][j]][mp[y][u]]+w[x]+w[y]+p[j][x]+p[u][y]);
			}
		}
		cout<<ans<<endl;
	}
}
