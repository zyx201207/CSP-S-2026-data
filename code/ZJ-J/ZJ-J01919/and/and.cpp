#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn = 0;
void dfs(int x,int g,int ans){
	if(ans <= maxn) return;
	if(x > m){
		maxn = max(maxn,ans);
		return;
	}
	for(int i = g + 1;i <= n;i++){
		dfs(x + 1,i,ans & a[i]);
	}
}
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	dfs(1,0,a[1]);
	cout << maxn;
}
