#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[305],f[305],k,o;
void dfs(int x,int y,int cnt){
	if(x==y){
		k=min(k,cnt);
		return ;
	}
	for(int i=x+1;i<=y;i++){
		if(d<abs(a[i]-a[x])){
			break;
		}
		dfs(i,y,cnt+1);
	}	
}
void dfs2(int x,int y,int cnt){
	if(x==y){
		if(k==cnt){
			o++;
		}
		return ;
	}
	for(int i=x+1;i<=y;i++){
		if(d<abs(a[i]-a[x])){
			break;
		}
		dfs2(i,y,cnt+1);
	}	
}
void solve(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			memset(f,0,sizeof(f));
			k=1e9,o=0;
			dfs(i,j,0);
			dfs2(i,j,0);
			if(o==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 
