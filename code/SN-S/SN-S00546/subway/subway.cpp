#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],f[510][510],s[500010],k[510],a,t,u,v;
vector<pair<long long,long long>>z[500010],l[510];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			l[i].push_back({a,t});
			z[a].push_back({i,t});
			s[a]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			f[i][j]=1e12;
		}
	}
	for(int i=1;i<=n;i++){
		for(auto it:l[i]){
			for(auto j:z[it.first]){
				f[i][j.first]=f[j.first][i]=min(f[i][j.first],it.second+j.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i) continue;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
/*		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	while(q--){
		cin>>u>>v;
		long long ans=w[u]+w[v],s=LLONG_MAX;
		for(auto i:z[u]){
			for(auto j:z[v]){
				s=min(s,f[i.first][j.first]+i.second+j.second);
			}
		}
		ans+=s;
		cout<<ans<<'\n';
	}
	return 0;
}

