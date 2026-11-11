#include<bits/stdc++.h>
using namespace std;
int a[220000],n,m,maxm=-114514;
void dfs(int id,int step,int maxv){
	if(id==n){
		return;
	}
	if(step==m){
		maxm=max(maxm,maxv);
		return;
	}else{
		if(maxv==0){
			dfs(id+1,step+2,a[0]&a[1]);
			dfs(id+1,step+1,a[0]);
			dfs(id+1,step,0);
		}else{
			dfs(id+1,step+1,maxv&a[id]);
			dfs(id+1,step,maxv);
		}
	}
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<maxm;
	return 0;
}
