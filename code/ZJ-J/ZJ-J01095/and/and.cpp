#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,ans=0,a[200010],ma,f[200010],j,s=0;
void dfs(int x,int ans,int t){
	int i;
	if(t==m){
		ma=max(ma,ans);
		return ;
	}
	for(i=x+1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			dfs(i,ans&a[i],t+1);
			f[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(i=2;i<=n;i++)
			ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
		cout<<ans;
		return 0;
	}
	if(n<=20||m==n-1){
		for(i=1;i<=n-m+1;i++)
			f[i]=1,dfs(i,a[i],1),f[i]=0;
		cout<<ma;
		return 0;
	}
	cout<<0;
	return 0;
}

