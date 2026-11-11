#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],x,y,ans;
void dfs(int b,int sum){
	if(b>y) return;
	if(b==y){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		int ok=0;
		for(int j=1;j<=n;i++){
			if(a[i][j]==b){
				ok=1;
				break;
			}
		}
		if(ok){
			for(int j=1;j<=k[i];j++) dfs(a[i][j],sum+w[i]+t[i][b]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		cin>>x>>y;
		ans=-2e9;
		dfs(x,0);
		cout<<ans<<"\n";
	}
	return 0;
} 
