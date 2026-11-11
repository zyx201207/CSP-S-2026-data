#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt;
int a[200010],ans;
void dfs(int u,int p,int sum){
	if(u>n+1||p>m+1)return;
	if(p==m+1){
//		cout<<sum<<' ';
		ans=max(ans,sum);
		return;
	}
	for(int i=u+1;i<=n;i++){
		dfs(u+1,p+1,sum&a[i]);
		dfs(u+1,p,sum);
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,2147483647);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
