#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100005],ans=0;
void dfs(int idx,int cnt,int sum){
	if(sum==m){
		ans=max(ans,cnt);
		return ;
	}
	if(idx==n+1) return ;
	int k=cnt&a[idx];
	if(cnt==-1) dfs(idx+1,a[idx],sum+1);
	else dfs(idx+1,k,sum+1);
	dfs(idx+1,cnt,sum);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<200000){
	dfs(1,-1,0);
	cout<<ans;
	}
	else{
	sort(a+1,a+n+1);
	int k=a[n];
	for(int i=n-1;i>=n-m+1;i--) k=k&a[i];
	cout<<k;
	}
	return 0;
}
