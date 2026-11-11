#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=1005;
int c,n,m,d,T,x,y,ans;
int w[N],k[N];
int a[M][M],t[M][M],b[M][M],vis[M][M];
queue<int> q[N];
void dfs(int op,int ch,int sum){
	if(ch==0||ch>k[op]) return;
	if(b[op][ch]==y){
		ans=min(ans,sum+t[op][y]);
		return;
	}
	if(!vis[op][ch-1]){
		vis[op][ch-1]=1;
		dfs(op,ch-1,sum);
		vis[op][ch-1]=0;
	}
	if(!vis[op][ch+1]){
		vis[op][ch+1]=1;
		dfs(op,ch+1,sum);
		vis[op][ch+1]=0;
	}
	for(int i=1;i<=n;i++){
		if(i==op||!a[i][b[op][ch]]) continue;
		if(!vis[i][a[i][b[op][ch]]]){
			vis[i][a[i][b[op][ch]]]=1;
			dfs(i,a[i][b[op][ch]],sum+t[op][b[op][ch]]+t[i][b[op][ch]]);
			vis[i][a[i][b[op][ch]]]=0;
		}
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		if(a[i][x]){
			vis[i][a[i][x]]=1;
			dfs(i,a[i][x],t[i][x]);
			vis[i][a[i][x]]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int A,B;
			cin>>A>>B;
			a[i][A]=j;
			b[i][j]=A;
			t[i][A]=B;
		}
	}
	while(T--){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				vis[i][a[i][j]]=0;
			} 
		}
		ans=2e17;
		solve();
		cout<<ans+w[x]+w[y]<<endl;	
	}
	return 0;
}