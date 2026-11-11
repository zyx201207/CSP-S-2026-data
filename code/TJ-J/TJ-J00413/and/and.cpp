#include<bits/stdc++.h>
using namespace std;
long long a[300000],ans=0,vis[300000];
long long n,m;
void dfs(long long cnt,long long sum){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(cnt==0){
				dfs(cnt+1,a[i]);
			}
			else{
				dfs(cnt+1,sum&a[i]);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	dfs(0,0);
	cout << ans;
	return 0;
}
