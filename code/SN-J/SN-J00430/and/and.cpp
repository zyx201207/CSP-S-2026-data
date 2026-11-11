#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[200005];
int ans=-10000;
void dfs(int i,int cnt,int mx){
	if(cnt>m){
		return;
	}
	if(i>n){	
		if(cnt==m){
			ans=max(mx,ans);	
		}
		return;
	}
	dfs(i+1,cnt+1,mx&a[i]);
	dfs(i+1,cnt,mx);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1,0,-1);
	cout << ans;
	return 0;
}
