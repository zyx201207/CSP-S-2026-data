#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200010],p[200010];
bool vis[200010];
void dfs(int u,int start){
	if(u==m+1){
		long long res=p[1];
		for(int i=2;i<=m;i++)res&=p[i];
		ans=max(ans,res);
	}
	for(int i=start;i<=n;i++){
		if(!vis[i]){
			p[u]=a[i];
			vis[i]=1;
			dfs(u+1,i+1);
			p[u]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
