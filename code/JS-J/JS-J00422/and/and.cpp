#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans,a[200010],b[200010];
int v[200010];
void dfs(int k){
	if(k==m+1){
		long long vis=b[1]&b[2];
		for(int i=3;i<=m;i++)vis&=b[i];
		ans=max(ans,vis);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			b[k]=a[i];
			v[i]=1;
			dfs(k+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}

