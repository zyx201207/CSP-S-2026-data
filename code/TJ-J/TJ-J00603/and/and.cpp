#include<bits/stdc++.h>
using namespace std;
int vis[200050]={0};
int box[200050]={0};
long long a[200050]={0};
int n,m;
int ans=-1;
void dfs(int x,int y,int ands){
	if(x==m+1){
		ans=max(ands,ans);
		return;
	}
	for(int i=y;i<=n;i++){
		if(vis[i]==0){
			box[x]=a[i];
			vis[i]=1;
			dfs(x+1,i,ands&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,0b1111111111111111111111111111111);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
