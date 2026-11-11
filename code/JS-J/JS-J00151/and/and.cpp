#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn;
bool vis[200005];
void dfs(int step,int val){
	if(step==n) return;
	if(step==m){
		maxn=max(maxn,val);
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(step+1,val&a[i]);
			vis[i]=0;
		}
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			maxn=max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	if(m==n){
		maxn=a[0];
		for(int i=1;i<n;i++){
			maxn=maxn&a[i];
		}
		cout << maxn;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	if(n<=20){
		dfs(0,2147483647);
		cout << maxn;
		return 0;
	}
	cout << a[n-m];
	return 0;
}
