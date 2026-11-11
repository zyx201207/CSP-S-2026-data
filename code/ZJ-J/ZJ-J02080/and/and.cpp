#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans=0;
void dfs(int step,int cnt,long long sum){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	if(n-step+1+cnt<m){
		return ;
	}
	if(sum<ans){
		return ;
	}
	dfs(step+1,cnt+1,(sum&a[step]));
	dfs(step+1,cnt,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,long(pow(2,31)-1));
	cout<<ans;
	return 0;
}
