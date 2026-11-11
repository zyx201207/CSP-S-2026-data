#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,inf=1e9+5;
int c,n,m,d,q2,a[N],e[N][25],sum[N][25];
struct node{
	int m,n,st;
};
queue<node>q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q2;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) e[i][j]=inf;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t,w;
			cin>>t>>w;
			e[t][i]=w;
		}	
	}
	while(q2--){
		int ans=inf;
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++) sum[i][j]=inf;
			
		}
		for(int i=1;i<=n;i++){
			if(e[x][i]!=inf) q.push(node{x,i,e[x][i]});
		}
		while(!q.empty()){
			node t=q.front();
			q.pop();
			if(t.st>ans) continue;
			if(t.m==y){
				ans=min(ans,t.st);
				continue;
			}
			if(t.st>sum[t.m][t.n]) continue;
			sum[t.m][t.n]=min(sum[t.m][t.n],t.st);
			for(int i=1;i<=m;i++){
				if(e[i][t.n]!=inf){
					q.push(node{i,t.n,t.st+e[i][t.n]});
					for(int j=1;j<=n;j++){
						if(e[i][j]!=inf){
							q.push(node{i,j,t.st+e[i][t.n]+e[i][j]});
						}
					}
				}
			}
		}
		cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
}

