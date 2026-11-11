#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int ans;
int arr[N];
void dfs(int u,int cur,int cnt){
	if(cnt>=m){
		ans=max(cur,ans);
		return;
	}
	if(u>=n){
		return;
	}
	int t=cur&arr[u+1];
	cout << t << endl;
	dfs(u+1,t,cnt+1);
	dfs(u+1,cur,cnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	dfs(0,(1<<30)-1,0);
	cout << ans;
	return 0;
}
