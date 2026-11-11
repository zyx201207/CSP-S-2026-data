#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx;
void dfs(int step,int pos,int ans){
	for(int i = pos+1;i <= n;i++){
		dfs(step+1,i,ans&a[i]);
	}
	if(step == m){
		maxx = max(ans,maxx);
		return ;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		maxx = 0;
		for(int i = 1;i <= n;i++){
			maxx = max(maxx,a[i]);
		}
		cout << maxx << "\n";
		return 0;
	}
	if(m == n){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			ans &= a[i];
		}
		cout << ans << "\n";
		return 0;
	}
	if(m == 2){
		int ans = 0;
		maxx = 0;
		for(int i = 1;i < n;i++){
			for(int j = i+1;j <= n;j++){
				ans = a[i] & a[j];
				maxx = max(maxx,ans);
			}
		}
		cout << maxx << "\n";
		return 0;
	}
	for(int i = 1;i <= n;i++){
		dfs(1,i,a[i]);
	}
	cout << maxx << "\n";
	return 0;
}
