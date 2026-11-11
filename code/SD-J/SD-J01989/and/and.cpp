#include<bits/stdc++.h>
using namespace std;
#define int long long
bool vis[100010];
int a[100010];
int ans=INT_MIN;
int cnt=1;
int n,m;
void dfs(int sum){
	if(cnt==m) ans=max(sum,ans);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			cnt++;
			dfs(sum&a[i]);
			cnt--;
			vis[i]=0;
		}
	}
}
signed main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	for(int i=1;i<=n;i++) cin >>a[i];
	for(int i=1;i<=n;i++){
		vis[i]=1;
		cnt=1;
		dfs(a[i]);
		vis[i]=0;
	}
	cout <<ans;
	
	return 0;
}
