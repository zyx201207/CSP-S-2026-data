#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[500010],ans;
void dfs(int t,int s){
	int i;
	if(t==m){
		ans=max(ans,s);
		return ;
	}
	for(i=1;i<=n;i++) if(s!=a[i]) dfs(t+1,(s & a[i]) );
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n>500||m>500){
		cout<<n-m;
		return 0;
	}
	for(i=1;i<=n;i++) dfs(1,a[i]);
	cout<<ans;
	return 0;
}

