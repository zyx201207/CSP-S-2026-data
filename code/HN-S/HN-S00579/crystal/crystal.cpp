#include <bits/stdc++.h> 
using namespace std;
int n,m,a[500009],ans=-1,dis[100002];
void dfs(int l){
	if(l==0){
		for(int i=1;i<=n;i++){
			ans=max(ans,dis[a[i]]);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dis[a[i]]++;
		dis[a[i]-1]--;
		l--;
		dfs(l);
		dis[a[i]]--;
		dis[a[i]-1]++;
		a[i]--;
		l++;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dis[a[i]]++;
	}
	dfs(m);
	cout<<ans;
	return 0;
}
