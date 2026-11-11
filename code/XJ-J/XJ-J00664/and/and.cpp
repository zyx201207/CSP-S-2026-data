#include<bits/stdc++.h>
using namespace std;

int a[200020],n,m,ans;

void dfs(int id,int sum,int cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}else if(id>n){
		return ;
	}
	if(sum==0){
		dfs(id+1,a[id],1);
		dfs(id+1,sum,0);
	}
	else{
		dfs(id+1,sum&a[id],cnt+1);
		dfs(id+1,sum,cnt);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}