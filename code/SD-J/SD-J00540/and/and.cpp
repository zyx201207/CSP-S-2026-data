#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans;
bool c[200005];
int d[200005];
void dfs(int i){
	if(i>m){
		int op=d[1];
		for(int i=2;i<=m;i++){
			op&=d[i];
		}
		ans=max(op,ans);
		return ;
	}
	for(int j=1;j<=n;j++){
		if(c[j]==0){
			d[i]=a[j];
			c[j]=1;
			dfs(i+1);
			d[i]=0;
			c[j]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
