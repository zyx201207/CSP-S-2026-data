#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000010];
long long cnt[2000100];
long long anss[2000100];
void dfs(int a,int ans,int y){
	if(a==n+1){
		if(anss[y]>ans) anss[y]=ans;
		anss[y]=0;
	}
	for(int i=a+1;i<=n;i++){
		if(x[i]-x[a]<=d) dfs(i,ans+1,i);
	}
}
int main() {
	freopen("migrate.in",r,stdin);
	freopen("migrate.out",w,stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		dfs(1,0,0);
	}
	int h=0;
	for(int i=1;i<=n;i++){
		if(anss[i]==2) h++;
	}
	cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
