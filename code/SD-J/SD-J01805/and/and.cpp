#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool b[200005];
int ans;
int n,m;
void dfs(int pos,int result){
	if (pos > m){
		ans = max(ans,result);
		return;
	} 
	for (int i = 1;i <= n;i++){
		if (!b[i]){
			b[i] = true;
			if (pos == 1){
				dfs(pos + 1,a[i]);
			} else{
		    	dfs(pos + 1,result & a[i]);
	    	}
			b[i] = false;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1,0);
	cout << ans << endl;
	return 0;
}
