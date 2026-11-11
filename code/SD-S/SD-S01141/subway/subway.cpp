#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int c,n,m,d,q,dp[maxn],w[maxn],vis[maxn];
struct node{
	int to,ti;
};
vector<node>G[maxn];
void dij(int v){
	memset(dp,0x3f,sizeof(dp));
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(v);
	dp[v]=0;
	while(!q.empty()){
		int nq=q.back();
		q.pop();
		if(vis[nq])continue;
		vis[nq]=1;
		for(int i=0;i<G[nq].size();i++){
			q.push(G[nq][i].to);
			dp[G[nq][i].to]=min(dp[G[nq][i].to],dp[nq]+G[nq][i].ti);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a[505],wi[505];
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>wi[j];	
		}	
		for(int j=1;j<k;j++){
			for(int p=j+1;p<=k;p++){
				G[a[j]].push_back({a[p],wi[j]+wi[p]});
				G[a[p]].push_back({a[j],wi[j]+wi[p]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int vi,wi;
		cin>>vi>>wi;
		dij(vi);
		cout<<dp[wi]+w[vi]+w[wi]<<endl;
	}
	
	
	return 0;
}


