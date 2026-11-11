#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans=0;
int n,m;
void dfs(int sum,int choose,int id){
	if(id>n){
		if(choose == m) ans=max(ans,sum);
		return;
	}
	//选择或者不选
	dfs(sum,choose,id+1);
	if(sum==0){
		dfs(a[id],choose+1,id+1);
	}else dfs(sum & a[id],choose+1,id+1); 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	} 
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
