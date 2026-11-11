#include<bits/stdc++.h>
using namespace std;
int n,m,a[20],ans=0;
void dfs(int step){
	if(step==m+1){
		int b[250]={0},res=0;
		for(int i=1;i<=n;i++)b[a[i]+100]++;
		for(int i=0;i<=200;i++)res=max(res,b[i]);
		ans=max(ans,res);
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(step+1);
		a[i]--;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}
