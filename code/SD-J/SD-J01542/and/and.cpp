#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],n,m,vis[N],ans,b[N];
void dfs(int u){
	if(u>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				b[++cnt]=a[i];
			}
		}
		if(cnt==m){
			int sum=b[1];
			for(int i=2;i<=cnt;i++){
				sum=sum&b[i];
				if(sum==0){
					break;
				}
			}
			ans=max(ans,sum);	
		} 
		return;
	}
	vis[u]=1;
	dfs(u+1);
	vis[u]=0;
	dfs(u+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n==m){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
