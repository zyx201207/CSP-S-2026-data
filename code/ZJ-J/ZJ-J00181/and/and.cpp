#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],bans;
void dfs(int k,int it,long long zhi){
	if(k==m){
		bans=max(bans,zhi);
		return ;
	}
	if(n-it+1==m-k){
		for(int i=it;i<=n;i++) zhi&=a[i];
		bans=max(bans,zhi);
		return ;
	}
	dfs(k+1,it+1,zhi&a[it]);
	dfs(k,it+1,zhi);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1 || m==n){
		long long mx=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			long long num;
			cin>>num;
			if(i==1) ans=num;
			else ans&=num;
			mx=max(mx,num);
		}
		if(m==1) cout<<mx;
		else cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++) cin>>a[i];
		long long ans=0,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=(a[i]&a[j]);
				ans=max(ans,sum);
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	long long k=1;
	for(int i=1;i<=30;i++) k*=2;
	k--;
	dfs(0,1,k);
	cout<<bans;
	return 0;
}
