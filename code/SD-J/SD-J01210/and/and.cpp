#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool f[200010];
int n,m;
int maxx=-1;
int ans;
void dfs(int cnt){
	if(cnt == m) return;
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i] = 1;
		int ans2 = ans;
		ans = ans & a[i];
		dfs(cnt+1);
		f[i] = 0;
		maxx=max(maxx,ans);
		ans=ans2;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans = a[i];
		dfs(1);
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
