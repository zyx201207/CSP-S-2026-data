#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
void dfs(int p,int len,int num){
	if(len>=m){
		ans=max(ans,num);
		return;
	}
	for(int i=p+1;i<=n;i++){
		dfs(i,len+1,num&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

