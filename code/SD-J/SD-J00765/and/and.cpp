#include <bits/stdc++.h>
using namespace std;
long long n,a[250000],m,maxand,vis[250000],maxans;
void dfs(int step,long long z){
	if(step-1==m){
		if(maxand<z){
			maxand=z;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			long long x=z&a[i];
			dfs(step+1,x);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(2,a[i]);
		vis[i]=0;
		maxans=max(maxans,maxand);
	}
	cout << maxans;
	return 0;
}
