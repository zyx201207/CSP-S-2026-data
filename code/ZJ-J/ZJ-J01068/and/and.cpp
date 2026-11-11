#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,ans,vis[200010],a[200010];
void dfs(int x,int res){
	int i;
	if(x==m+1){
		ans=max(ans,res);
		return;
	}
	for(i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,(res&a[i]));
			vis[i]=0;
		}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,1048575);
		cout<<ans;
		return 0;
	}
	if(n<=2000){
		if(m==1){
			for(i=1;i<=n;i++) ans=max(ans,a[i]);
			cout<<ans;
			return 0;
		}
		if(m==n){
			ans=a[1];
			for(i=2;i<=n;i++) ans=(ans&a[i]);
			cout<<ans;
			return 0;
		}
		if(m==2){
			for(i=1;i<=n;i++)
				for(j=i+1;j<=n;j++)
					ans=max(ans,(a[i]&a[j]));
			cout<<ans;
			return 0;
		}
	}
	if(m==n-1){
		dfs(1,1048575);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(i=n-1;i>=n-m+1;i--) ans=(ans&a[i]);
	cout<<ans;
}
