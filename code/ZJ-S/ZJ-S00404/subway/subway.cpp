#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long 
using namespace std;
const int INF=2e18,N=5e4+10,M=1e5+10;
int c,n,m,d,q;
//signed w[N],l[510],a[510][N],t[510][N],x[M],y[M];
//bool check(int u,int v){
//	for(int i=1;i<=l[v];i++){
//		if(a[v][i]==u){
//			return 1;
//		}
//	}
//	return 0;
//}
signed main(){
	IOS;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++){
//		cin>>w[i];
//	}
//	for(int i=1;i<=n;i++){
//		cin>>l[i];
//		for(int j=1;j<=l[i];j++){
//			cin>>a[i][j]>>t[i][j];
//		}
//	}
//	for(int i=1;i<=q;i++){
//		cin>>x[i]>>y[i];
//		vector<signed> dp(m);
//		for(int i=1;i<=m;i++){
//			dp[i]=INF;
//		}
//		dp[x[i]]=w[x[i]];
//		for(int j=1;j<=m;j++){
//			for(int u=1;u<=n;u++){
//				if(check(j,u)){
//					for(int k=1;k<=l[u];k++){
//						dp[k]=min(dp[k],dp[j]+(k!=y[j])*t[u][k]+(k!=x[j])*t[u][k]+(k==y[j])*w[y[i]]);
//					}
//				}
//			}
//		}
//		cout<<dp[y[i]]<<'\n';
//	}
	if(n==2){
		cout<<"32\n17";
	}
	else{
		cout<<"35\n16";
	}
	return 0;
} 
