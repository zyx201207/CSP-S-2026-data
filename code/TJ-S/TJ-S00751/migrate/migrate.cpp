#include<bits/stdc++.h>
using namespace std;
long long a[10000000],b[1000000];
int dfs(int be,int en,int fly){
	if(be==en){
		return a[be];
	}
	for(int i=1;i<=fly;i++){
		if(be+i<=en) return dfs(be+i,en,fly);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,m,maxx=-999;
		cin>>n>>m;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				b[dfs(i,i+j,m)]++;
			}
		}
		int tmp=0;
		for(int i=1;i<=maxx;i++){
			cout<<b[i]<<" ";
			if(b[i]>=2){
				tmp++;
			}
		}
		cout<<tmp<<endl;
	}
	return 0;
}
