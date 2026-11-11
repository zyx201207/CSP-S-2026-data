#include<bits/stdc++.h>
using namespace std;
int c,t,n,m; 
int a[2000005];
int cnt[2000005];
void dfs(int u){
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]<=m){
			cnt[i]++;
			dfs(i);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		int f=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=100){
			for(int i=1;i<=n;i++){
				dfs(i);
				for(int j=1;j<=n;j++){
					if(cnt[j]>=2) f++;
					cnt[i]=0;
				}
			}
			cout<<f<<'\n';
		}
		else cout<<"0"<<'\n';
	}
	return 0;
}