#include<bits/stdc++.h>
using namespace std;
int n,m;
int ar[200005];
int ans=-2e9;
void dfs(int l,int cnt,int maxnow){
	if(cnt==m) {
		ans=max(ans,maxnow);
		return ;
	}
	if(l==n+1) return ;
	
	dfs(l+1,cnt+1,maxnow&ar[l]);
	dfs(l+1,cnt,maxnow);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int maxar=-2e9,maxr=-2e9;
	long long sum;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		maxar=max(maxar,ar[i]);
		sum+=ar[i];
	}
	long long a=n/2*(n-1);
	if(a==sum){
		cout<<n-m;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			maxr=max(maxr,ar[i]&ar[j]);
		}
	}
	if(m==1){
		cout<<maxar;
		return 0;
	}
	if(m==2){
		cout<<maxr;
		return 0;
	}
	dfs(1,0,INT_MAX);
	cout<<ans;
	return 0;
}