#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int sum = -1e9;
int vis[200005];

void dfs(int step=1,int k=0){
	if(step>=m){
		sum = max(sum,k);
		return;
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			k&=a[i]; 
			vis[i]=1;
			dfs(step+1,k);
			vis[i]=0;
		}
		
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i]);
	}
	cout << sum;
	return 0;
}
