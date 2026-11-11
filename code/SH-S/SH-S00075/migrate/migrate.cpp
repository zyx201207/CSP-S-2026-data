#include<bits/stdc++.h>
using namespace std;
int a[15];
int n,d,ans,mi=10000;
int vis[15];
void dfs(int j,int now,int l){
	if(now==j){
		if(l>mi)return;
		if(l==mi)ans++;
		else ans=1,mi=l;
		return;
	}
	for(int k=now+1;k<=j;k++){
		if(a[now]+d<a[k])break;
		if(!vis[k]){
			vis[k]=1;
			dfs(j,k,l+1);
			vis[k]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
	int cnt=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j)continue;
			ans=0;mi=10000;
			dfs(j,i,0);
			if(ans==2)cnt++;
		}
	}
	cout<<cnt<<endl;
	}
	return 0;
}
