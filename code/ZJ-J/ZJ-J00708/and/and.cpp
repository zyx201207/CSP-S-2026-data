#include<bits/stdc++.h>
using namespace std;
const int mn = 2e5+9;
int n,m;
int a[mn];
bool vis[mn];
long long pre[mn],ans = -1e18;
void dfs(int x,int tot,long long sum){
	if(tot==m){
		ans = max(ans,sum);
		return ; 
	}
	if(x==n+1)return ;
	if(n+1-x<m-tot)return ;
	if(n+1-x==m-tot){
		for(int i=x;i<=n;i++){
			sum&=a[i];
		}
		ans = max(ans,sum);
		return ;
	}
	vis[x] = 1;
	dfs(x+1,tot+1,sum&a[x]);
	vis[x] = 0;
	dfs(x+1,tot,sum);
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cout << (1^0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1,0,1<<32-1);
	cout << ans;
	return 0;
}
