#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1,cnt=0;
int a[200005];
void dfs(int s,int e,int now){
	cnt++;
	if(cnt>2e10){
		return ;
	}
	if(e+m-s>n){
		return ;
	}
	if(e==m){
		ans=max(ans,now);
		return ;
	}
	for (int i=s+1;i<=n;i++){
		dfs(i,e+1,a[s]&a[i]);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for (int i=1;i+m<=n;i++){
		dfs(1,0,a[i]);
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


