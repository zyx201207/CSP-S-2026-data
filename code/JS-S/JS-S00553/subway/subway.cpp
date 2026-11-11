#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q1;
long long mn;
vector<pair<int,int>> q[500010];
vector<int> pa[500010],pi[500010];
int w[500010],df[510][500010];
bool v[500010];
void dfs(int u,int i,int my,long long sum){
	if(u==my){
		mn=min(mn,sum+df[i][u]);
		return ;
	}
	for(pair<int,int> val:q[u])
		if(!v[val.first]&&val.second==i){
			v[val.first]=1;
			dfs(val.first,i,my,sum);
			v[val.first]=0;
		}
	for(int vi:pa[u])
		for(int va:pi[vi])
			if(!v[va]&&vi!=i){
				v[va]=1;
				dfs(va,vi,my,sum+df[i][u]+df[vi][u]);
				v[va]=0;
			}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k;i<=n;i++){
		int fa=0;
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			pa[a].push_back(i);
			pi[i].push_back(a);
			q[a].push_back({fa,i});
			q[fa].push_back({a,i});
			df[i][a]=t;
			fa=a;
		}
	}
	while(q1--){
		int x,y;
		cin>>x>>y;
		mn=LONG_LONG_MAX;
		v[0]=1;
		v[x]=1;
		for(int i:pa[x])
			dfs(x,i,y,w[x]+w[y]+df[i][x]);
		v[x]=0;
		cout<<mn<<'\n';
	}
	return 0;
}