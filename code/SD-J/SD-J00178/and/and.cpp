#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define int long long 
int n,m,a[N],ans;
void dfs(int x,int cnt,int sum){
	if(x==n+1){
		if(cnt==m){
			ans=max(ans,sum);
		}
		return ;
	}
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	if(cnt==0) {
		dfs(x+1,cnt+1,a[x]);
	}
	else dfs(x+1,cnt+1,a[x]&sum);
	dfs(x+1,cnt,sum);
}
bool sub_a(){
	for(int i=1;i<=n;i++){
		int lg=log2(a[i]);
		int pw=(1ll<<lg)-1;
		if(pw!=a[i]) return false;
	}
	return true;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(m==1){
		int ans1=0;
		for(int i=1;i<=n;i++){
			ans1=max(ans1,a[i]);
		}
		cout<<ans1;
		return 0;
	}
	else if(m==2){
		int ans1=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans1=max(ans1,a[i]&a[j]);
			}
		}
		cout<<ans1;
		return 0;
	}
	else if(m==n){
		int ans1=a[1];
		for(int i=2;i<=n;i++) ans1=ans1&a[i];
		cout<<ans1;
		return 0;
	}
	else if(sub_a()){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
    dfs(1,0,0);
    cout<<ans;
	return 0;
}

