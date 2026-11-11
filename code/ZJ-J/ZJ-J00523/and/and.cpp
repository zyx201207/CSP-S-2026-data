#include<bits/stdc++.h>
using namespace std;
long long ans,a[200009],n,m;
void dfs(int x,int last,int sum){
	if(x==m){
		if(ans<sum)ans=sum;
		return ;
	}
	if(last==n)return ;
	for(int i=last+1;i<=n;i++){
		dfs(x+1,i,sum&a[i]);
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
		dfs(1,i,a[i]);
	}
	cout<<ans;
}
