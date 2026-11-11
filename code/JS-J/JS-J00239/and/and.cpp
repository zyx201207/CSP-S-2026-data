#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],vh[2010][5][2010],l=0,ans=0;
int f(int t,int u){
	if(vh[t][u][l]!=-1) return vh[t][u][l];
	if(t>n) return vh[t][u][l]=0;
	if(u==m) return vh[t][u][l]=a[l];
	if(t==l) return vh[t][u][l]=f(t+1,u);
	return vh[t][u][l]=max(f(t+1,u+1)&a[t],f(t+1,u));
}
void dfs(int t,int u,int p){
	if(u==m){
		ans=max(ans,p);
		return;
	}
	if(t>n) return;
	if(t==l){
		dfs(t+1,u,p);
	}else{
		dfs(t+1,u+1,p&a[t]);
		dfs(t+1,u,p);
	}
	
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(vh,-1,sizeof(vh));
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			l=i;
			dfs(1,1,a[i]);
		}
	}else{
		for(int i=1;i<=n;i++){
			l=i;
			ans=max(ans,f(1,1));
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
