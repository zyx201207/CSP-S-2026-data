#include<bits/stdc++.h>
using namespace std;
const int N=5e2+50,M=5e5+50;
int c,n,m,d,q,ans,w[M],s,se,v[M],x[M],t[N][M];
struct E{
	int x,i;
};
vector<E>e[M];
void dfs(int u,int b,int i){
	if(u==se){
		ans=min(t[i][u]+b,ans);
		return ;
	}
	for(auto k:e[u]){
		if(!v[k.x]){
			v[k.x]=1;
			int c=0;
			if(k.i!=i)c+=t[i][u]+t[k.i][u];
			dfs(k.x,b+c,k.i);
			v[k.x]=0;
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[j];
			cin>>t[i][x[j]];
			for(int c=1;c<j;c++){
				e[x[j]].push_back({x[c],i});
				e[x[c]].push_back({x[j],i});
			}
		}
	}
	while(q--){
		cin>>s>>se;
		ans=1e9;
		for(int i=1;i<=n;i++)v[i]=0;
		for(int i=1;i<=n;i++){
			if(t[i][s]){
				v[s]=1;
				dfs(s,t[i][s],i);
			}
		}
		ans+=w[se]+w[s];
		cout<<ans<<"\n";
	}
	return 0;
}
/*
10+
*/
