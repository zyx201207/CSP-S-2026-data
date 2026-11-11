#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int ans[205],mp[2005],vis[2005];
void check(){
	int now=mp[ans[1]];
	for(int i=2;i<=m;i++) now&=mp[ans[i]];
	cnt=max(cnt,now);
}
void dfs(int dep){
	if(dep>m) {check();return;}
	for(int j=1;j<=n;j++){
		if(!vis[j]){
			ans[dep]=j;
			vis[j]=1;
			dfs(dep+1);
			vis[j]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> mp[i];
	dfs(1);
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
