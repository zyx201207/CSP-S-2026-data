 #include <bits/stdc++.h>
using namespace std;
int a[200005];
int ans=-2e9,n,m;
void dfs (int step,int cnt,int zhi){
	if (step>n||cnt==m){
		if (cnt==m){
			ans=max(ans,zhi);
		}
		return;
	}
	dfs (step+1,cnt,zhi);
	if (cnt==0) dfs (step+1,cnt+1,a[step]);
	else dfs (step+1,cnt+1,a[step]&zhi);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs (1,0,0);
	cout <<ans;
	return 0;
}