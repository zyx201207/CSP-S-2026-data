#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200050];
bool vis[200050];
long long ma=0;
void dfs(int cur,int pre){
	if(cur==m){
		long long ans=1;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				ans&=a[i];
			}
		}
		ma=max(ma,ans);
		return;
	}
	for(int i=pre+1;i<=n-m+cur+1;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(cur+1,i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		int ans=1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n-1){
		int ans=0;
		for(int i=1;i<=n;i++){
			int cnt;
			int t;
			if(i==1)t=2;
			else t=1;
			cnt=a[t];
			for(int j=t+1;j<=n;j++){
				if(i==j)continue;
				cnt=cnt&a[j];
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}else{
		dfs(0,0);
		cout<<ma;
	}
	return 0;
}
