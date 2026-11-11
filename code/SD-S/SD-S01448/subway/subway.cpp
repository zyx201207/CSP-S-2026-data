#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+1000;
const long long INF=1e18;
int c,n,m,d,q,w[M],kk; 
int S,T;
long long dp[N][N],anss;
vector<int> vec_a[N],vec_t[N];
struct node{
	int x,w;
};
vector<node> e[M];
void floyd(){
	for(int k=1;k<=n;k++){//O(n*n*n)
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//O(m)
		cin>>kk;
		for(int j=1;j<=kk;j++){
			int a,t;
			cin>>a>>t;
			e[a].push_back((node){i+m,t});
		}
	}
	for(int i=1;i<=n;i++){//O(n*n)
		for(int j=1;j<=n;j++){
			dp[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){//O(m*d*d) 
		for(int j=0;j<(int)e[i].size();j++){
			for(int k=j+1;k<(int)e[i].size();k++){
				int u=e[i][j].x,v=e[i][k].x;
				int w1=e[i][j].w,w2=e[i][k].w;
				dp[u-m][v-m]=min(dp[u-m][v-m],1ll*(w1+w2));
				dp[v-m][u-m]=min(dp[v-m][u-m],1ll*(w1+w2));
			}
		}
	}
	floyd();
	while(q--){//O(q*d*d) 
		cin>>S>>T;
		anss=INF;
		for(int i=0;i<(int)e[S].size();i++){
			for(int j=0;j<(int)e[T].size();j++){
				int u=e[S][i].x,v=e[T][j].x;
				int w1=e[S][i].w,w2=e[T][j].w;
				anss=min(anss,1ll*w1+1ll*w2+dp[u-m][v-m]);
			}
		}
		cout<<anss+1ll*w[S]+1ll*w[T]<<'\n';
	}
	return 0;
}
