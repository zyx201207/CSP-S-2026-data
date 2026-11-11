#include<bits/stdc++.h>
#define N 510
#define M 500010
#define ll long long
#define MAX 1000000000000000000ll
using namespace std;
struct node{
	int u,v;
	ll w;
};
int c,n,m,d,q;
ll w[M],k[N],to[N][N];
vector<node> ve[M];
void f(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i)continue;
			for(int j=1;j<=n;j++){
				if(k==j||i==j)continue;
				if(to[i][k]==0||to[k][j]==0)continue;
				to[i][j]=min(to[i][j],to[i][k]+to[k][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)to[i][j]=MAX;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a;
			ll t;
			cin>>a>>t;
			ve[a].push_back({a,i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:ve[i]){
			for(auto y:ve[i]){
				if(x.u==y.u&&x.v==y.v&&x.w==y.w)continue;
				to[x.v][y.v]=x.w+y.w;
				to[y.v][x.v]=x.w+y.w;
			}
		}
	}
	f();
	while(q--){
		int a,b;
		ll ans=MAX;
		cin>>a>>b;
		for(auto x:ve[a]){
			for(auto y:ve[b]){
				if(to[x.v][y.v]!=MAX){
					ans=min(ans,to[x.v][y.v]+x.w+y.w);
				}else if(x.v==y.v){
					ans=min(ans,x.w+y.w);
				}
			}
		}
		cout<<ans+w[a]+w[b]<<"\n";
	}
	return 0;
}
