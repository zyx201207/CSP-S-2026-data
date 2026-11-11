#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
int n,m;
int ans = -1;
void dfs(int dq,int xz,int sum){
	if(xz==m){
		ans = max(ans,sum);
		return;
	}
	if(n-dq+1<m-xz) return;
	if(a[dq]!=0){
		if(xz==0){
			dfs(dq+1,xz+1,a[dq]);
		}else{
			dfs(dq+1,xz+1,sum&a[dq]);
		}
	}
	dfs(dq+1,xz,sum);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}