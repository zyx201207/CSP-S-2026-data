#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0,res=INT_MAX;
int a[200010];
bool f[200010];
void dfs(int x){
	if(x==m){
		ans=max(res,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			int s=res;
			res&=a[i];
			f[i]=true;
			dfs(x+1);
			res|=s;
			f[i]=false;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}