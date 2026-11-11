#include<bits/stdc++.h>
using namespace std;
int n,m,maxn = 0;
int a[20010],vis[20010],b[20010];
void dfs(int x){
	if(x==m-1){
		int ans = b[0];
		for(int i = 0;i<m;i++){
			ans = ans&b[i];
			b[i] = 0;
		}
		if(ans>maxn){
			maxn = ans;
		}
	}
	for(int i = 0;i<n;i++){
		if(vis[i]==0){
			vis[i] = 1;
			b[x] = a[i];
			dfs(x+1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);

	return 0;
}

