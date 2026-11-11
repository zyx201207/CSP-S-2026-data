#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,c,a[2000002],d,n;
int dfs(int p,int t){
	if(p==t) return 1;
	int res;
	for(int i=p+1;i<=t;i++){
		if(a[i]-a[p]>d) break;
		else res+=dfs(i,t);
	}
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++) cnt+=(dfs(i,j)==2); 
		}
		cout<<cnt;
	}
}
