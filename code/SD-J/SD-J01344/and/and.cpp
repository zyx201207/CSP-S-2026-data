#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
long long a[N];
int vis[N];
long long ans_1=a[1];
void dfs(int u,long long ans){
	if(u>=m){
		ans_1=max(ans_1,ans);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(u+1,ans&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(m==1){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(n<=20){
		dfs(1,a[1]);
		cout<<ans_1;
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]){
					ans=a[i];
				}
			}
		}
		if(ans!=0){
			cout<<ans;
		}else{
			dfs(1,a[1]);
			cout<<ans_1;
		}
	}else if(m==n-1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				ans&=a[i];
			}
		}
		cout<<ans;
	}
	return 0;
}
