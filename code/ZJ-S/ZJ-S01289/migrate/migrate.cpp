#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[2000010],ans1,ans2;
void dfs(int x,int u,int v,int d){
	if(x>v) return ;
	if(x==v){
		if(ans1>d) ans1=d,ans2=1;
		else if(ans1==d) ans2++;
		return ;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=m) dfs(i,u,v,d+1);
		else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans1=1e18,ans2=0;
				dfs(i,i,j,0);
				ans+=(ans2==2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
