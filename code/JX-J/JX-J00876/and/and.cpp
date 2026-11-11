#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],box[200005];
bool vis[200005];
int ans;
bool f=1;
void dfs(int x){
	if(x==m+1){
		int sum=box[1];
		for(int i=2;i<=m;i++){
			sum&=box[i];
		}
		ans=max(ans,sum);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]!=1){
			box[x]=a[i];
			vis[i]=1;
			dfs(x+1);
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
	for(int i=1;i<n-1;i++){
		if(a[i]!=a[i+1]) f=0;
	}
	if(f){
		cout<<a[1]<<endl;
		return 0;
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
