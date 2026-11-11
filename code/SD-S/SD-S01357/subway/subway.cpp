#include<bits/stdc++.h>
#define ll long long
#define P pair<int,int>
using namespace std;
const int maxN=2e3+10;
const ll INF=1e18+10;
ll c,n,m,d,q,s,t,f[maxN],b[maxN],fa[maxN],w,ans,g[maxN][maxN];
void _(){
	cin>>s>>t,ans=0ll;
	cout<<g[s][t]<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=n+m;i++)
		for(int j=0;j<=n+m;j++) g[i][j]=INF;
	for(int i=1;i<=m;i++) cin>>w,g[0][i]=g[i][0]=w;
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,v;j<=k;j++) 
			cin>>v>>w,g[i+m][v]=g[v][i+m]=w;
	}
	for(int k=0;k<=n+m;k++)
		for(int i=0;i<=n+m;i++)
			for(int j=0;j<=n+m;j++) g[i][j]=min(g[i][j],g[k][i]+g[j][k]);
//	for(int i=0;i<=n+m;i++){
//		for(int j=0;j<=n+m;j++){
//			cout<<g[i][j]<<' ';
//			//if(i==j&&g[i][j]!=INF) cout<<"?";
//		} 
//		cout<<endl;
//	}
	while(q--)_();
	return 0;
} 
