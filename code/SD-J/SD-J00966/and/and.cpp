#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans,vis[200005];
void dfs(ll b,ll res){
	if(b>m){
		ans=max(ans,res);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(b+1,res&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		ans==pow(2,32)-1;
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}else{
		dfs(1,pow(2,32)-1);
		cout<<ans;
	}
	return 0;
}

