#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
int n,m,maxx=1,a[maxn],dp[maxn];
void dfs(int k,int c,int ans){
	//printf("k=%d,c=%d,ans=%d\n",k,c,ans);
	if(c==m){
		//cout<<"DFS exit Code 1:c==m=="<<m<<'\n';
		if(ans!=INT_MAX) maxx=max(maxx,ans);
		return;
	}
	if(k==n+1){
		//cout<<"DFS exit Code 2:k==n=="<<n<<'\n';
		return;
	}
	dfs(k+1,c,ans);
	dfs(k+1,c+1,ans&a[k]);
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	//70 pts
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//code
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) dp[i]=a[i];
	}
	dfs(1,0,INT_MAX);
	cout<<maxx;
	return 0;
}
