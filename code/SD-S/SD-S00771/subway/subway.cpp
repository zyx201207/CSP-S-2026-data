#include<bits/stdc++.h>
using namespace std;
long long n,m,w[500005],k[505],a[505],b[505][100005];
long long s,c,d,q,vis[500005];
int y;
vector<pair<long long,int> > v[500005];
void dfs(int x,int p){
	vis[x]=1;
	if(x==y){
		return ;
	} 
	for(int i=0;i<v[x].size();i++){
		long long g=v[x][i].first;
		if(vis[g]==0){
			if(p!=v[x][i].second){
				s+=b[v[x][i].second][x];
			}
			s+=b[p][x];
			dfs(g,v[x][i].second);
			vis[g]=0;
			s-=b[p][x];
			if(p!=v[x][i].second){
				s-=b[v[x][i].second][x];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[j],&b[i][j]);
			if(j>=2){
				v[a[j]].push_back({a[j-1],i});
				v[a[j-1]].push_back({a[j],i});	
			}
		}
	}
	for(int i=1;i<=q;i++){
		s=0;
		int x;
		cin>>x>>y;
		s=s+w[x]+w[y];
		dfs(x,1);
		cout<<s<<"\n";
	}
	return 0;
} 
