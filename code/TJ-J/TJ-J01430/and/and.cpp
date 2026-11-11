#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,m;
unsigned int a[N],ans;
bool vis[N];
void dfs(unsigned int aa,int sum){
	if(sum>=m){
		ans=max(ans,aa);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(aa&a[i],sum+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		unsigned int ans=INT_MAX;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}cout<<ans;
	}else if(n<=2000){
		dfs(2147483647u,0);
		cout<<ans;
	}else{
		cout<<0;
	}
	
	return 0;
}
