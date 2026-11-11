#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500,M=5e5;
const ll inf=1e17;
ll wx[M+2];
struct node{
	int x;
	ll w;
};
vector<vector<node> >g(M+2);
ll f[N+2][N+2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int yld,n,m,ddjtsx,q;
	cin>>yld>>n>>m>>ddjtsx>>q;
	for(int i=1;i<=m;i++){
		cin>>wx[i];
	}
	int k,oa,ot;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>oa>>ot;
			g[oa].push_back({i,ot});
		}
	}
	fill(&f[1][1],&f[n][n+1],inf);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j1=0;j1<g[i].size();j1++){
			for(int j2=j1+1;j2<g[i].size();j2++){
				node& j1x=g[i][j1];
				node& j2x=g[i][j2];
				f[j1x.x][j2x.x]=min(f[j1x.x][j2x.x],j1x.w+j2x.w);
				f[j2x.x][j1x.x]=min(f[j2x.x][j1x.x],j1x.w+j2x.w);
				//cout<<j1x.w+j2x.w<<"\n";
			}
		}
	}
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			if(p==i) continue;
			for(int j=i+1;j<=n;j++){
				if(p==j) continue;
				if(f[i][j]>f[i][p]+f[p][j]){
					f[i][j]=f[i][p]+f[p][j],f[j][i]=f[j][p]+f[p][i];
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
	*/
	int x,y;
	while(q--){
		cin>>x>>y;
		ll ans=inf;
		for(int j1=0;j1<g[x].size();j1++){
			for(int j2=0;j2<g[y].size();j2++){
				ans=min(ans,g[x][j1].w+g[y][j2].w+f[g[x][j1].x][g[y][j2].x]);
				//cout<<g[x][j1].x<<" "<<g[x][j1].w<<" "<<g[y][j2].x<<" "<<g[y][j2].w<<"\n";
				//cout<<g[x][j1].w<<"+"<<g[y][j2].w<<"+"<<f[g[x][j1].x][g[y][j2].x]<<"\n";
			}
		}
		cout<<ans+wx[x]+wx[y]<<"\n";
	}
	return 0;
}
