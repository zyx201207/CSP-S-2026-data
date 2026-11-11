#include<bits/stdc++.h>
using namespace std;
long long a[200001],f[200001],ans=0,n,m;
void dfs(long long step,long long aa){
	if(step==0){
		ans=max(ans,aa);
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1)continue;
		f[i]=1;
		dfs(step-1,aa&a[i]);
		f[i]=0;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(m,2147483647);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
