#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool b[200005];
long long t[200005];
long long n,m;
long long ans1;
void dfs(long long step){
	if(step==m+1){
		long long ans=(long long)pow(2,30)-1;
		for(int i=1;i<=m;i++){
			ans=ans&t[i];
		}
		ans1=max(ans1,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			t[step]=a[i];
			dfs(step+1);
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
	if(n==m){
		long long ans=(long long)pow(2,30)-1;
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			long long ans1=(long long)pow(2,30)-1;
			for(long long j=1;j<=n;j++){
				if(i!=j){
					ans1=ans1&a[i];
				}
			}
			ans=max(ans,ans1);
		}
		cout<<ans;
		return 0;
	}
	else {
		dfs(1);
		cout<<ans1;
		return 0;
	}
	return 0;
}
