#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans;
void dfs(long long x,long long da,long long sl){
	if(sl==m) ans=max(ans,da);
	for(int i=x;i<=n;i++){
		if(sl==0) {
			dfs(i+1,a[i],sl+1);
		}else{
			dfs(i+1,da&a[i],sl+1);
		}
		dfs(i+1,da,sl);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
